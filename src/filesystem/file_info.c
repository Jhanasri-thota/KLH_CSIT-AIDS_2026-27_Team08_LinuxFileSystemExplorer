#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

#include "../include/file_info.h"

void display_file_info(const char *filename)
{
    struct stat file_stat;

    if (stat(filename, &file_stat) == -1)
    {
        perror("Error getting file information");
        return;
    }

    printf("\n========================================\n");
    printf("          FILE INFORMATION\n");
    printf("========================================\n");

    printf("File Name      : %s\n", filename);
    printf("File Size      : %ld bytes\n", (long)file_stat.st_size);
    printf("Inode Number   : %ld\n", (long)file_stat.st_ino);
    printf("Number of Links: %ld\n", (long)file_stat.st_nlink);
    printf("Owner UID      : %ld\n", (long)file_stat.st_uid);
    printf("Group GID      : %ld\n", (long)file_stat.st_gid);

    printf("Permissions    : %o\n", file_stat.st_mode & 0777);

    printf("Last Access    : %s", ctime(&file_stat.st_atime));
    printf("Last Modified  : %s", ctime(&file_stat.st_mtime));

    printf("========================================\n");
}
