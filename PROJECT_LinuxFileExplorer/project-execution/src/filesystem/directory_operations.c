#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

#include "../include/directory_operations.h"

/* List directory contents */
void list_directory(const char *path)
{
    DIR *directory;
    struct dirent *entry;

    directory = opendir(path);

    if (directory == NULL)
    {
        perror("Error opening directory");
        return;
    }

    printf("\n========================================\n");
    printf("       DIRECTORY CONTENTS\n");
    printf("========================================\n");
    printf("Directory: %s\n\n", path);

    while ((entry = readdir(directory)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    if (closedir(directory) == -1)
    {
        perror("Error closing directory");
        return;
    }

    printf("========================================\n");
}

/* Create a new directory */
void create_directory(const char *dirname)
{
    if (mkdir(dirname, 0755) == -1)
    {
        perror("Error creating directory");
        return;
    }

    printf("Directory created successfully: %s\n", dirname);
}

/* Remove an empty directory */
void remove_directory(const char *dirname)
{
    if (rmdir(dirname) == -1)
    {
        perror("Error removing directory");
        return;
    }

    printf("Directory removed successfully: %s\n", dirname);
}

/* Change current working directory */
void change_directory(const char *path)
{
    if (chdir(path) == -1)
    {
        perror("Error changing directory");
        return;
    }

    printf("Directory changed successfully to: %s\n", path);
}

/* Display current working directory */
void show_current_directory(void)
{
    char current_directory[PATH_MAX];

    if (getcwd(current_directory, sizeof(current_directory)) == NULL)
    {
        perror("Error getting current directory");
        return;
    }

    printf("\n========================================\n");
    printf("       CURRENT DIRECTORY\n");
    printf("========================================\n");
    printf("%s\n", current_directory);
    printf("========================================\n");
}
