#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "../include/file_operations.h"

void create_file(const char *filename)
{
    int fd = open(filename, O_CREAT | O_EXCL, 0644);

    if (fd == -1)
    {
        perror("Error creating file");
        return;
    }

    printf("File created successfully: %s\n", filename);
    close(fd);
}

void write_file(const char *filename, const char *content)
{
    int fd = open(filename, O_WRONLY | O_TRUNC);

    if (fd == -1)
    {
        perror("Error opening file for writing");
        return;
    }

    ssize_t bytes_written = write(fd, content, strlen(content));

    if (bytes_written == -1)
        perror("Error writing to file");
    else
        printf("File written successfully: %s\nBytes written: %ld\n",
               filename, (long)bytes_written);

    close(fd);
}

void read_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file for reading");
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;

    printf("\n========================================\n");
    printf("           FILE CONTENT\n");
    printf("========================================\n");

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read == -1)
        perror("Error reading file");

    printf("\n========================================\n");

    close(fd);
}

void delete_file(const char *filename)
{
    if (unlink(filename) == -1)
    {
        perror("Error deleting file");
        return;
    }

    printf("File deleted successfully: %s\n", filename);
}

void seek_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }

    off_t position = lseek(fd, 0, SEEK_END);

    if (position == -1)
    {
        perror("Error using lseek");
        close(fd);
        return;
    }

    printf("\n========================================\n");
    printf("          FILE SEEK INFORMATION\n");
    printf("========================================\n");

    printf("File size / end position: %ld bytes\n",
           (long)position);

    position = lseek(fd, 0, SEEK_SET);

    printf("File position after SEEK_SET: %ld\n",
           (long)position);

    close(fd);

    printf("========================================\n");
}
