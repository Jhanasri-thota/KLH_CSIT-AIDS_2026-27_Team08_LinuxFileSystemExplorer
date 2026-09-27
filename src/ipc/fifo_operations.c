#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#include "../include/fifo_operations.h"

void fifo_communication(void)
{
    const char *fifo_name = "ossp_fifo";

    char message[] = "Hello through FIFO!";
    char buffer[100];

    if (mkfifo(fifo_name, 0666) == -1)
    {
        /* FIFO may already exist */
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        int fd = open(fifo_name, O_RDONLY);

        if (fd == -1)
        {
            perror("open FIFO for reading");
            exit(EXIT_FAILURE);
        }

        read(fd, buffer, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';

        printf("\nChild received through FIFO: %s\n", buffer);

        close(fd);
        exit(0);
    }
    else
    {
        int fd = open(fifo_name, O_WRONLY);

        if (fd == -1)
        {
            perror("open FIFO for writing");
            return;
        }

        write(fd, message, strlen(message) + 1);

        printf("\nParent sent through FIFO: %s\n", message);

        close(fd);

        wait(NULL);

        unlink(fifo_name);

        printf("FIFO communication completed.\n");
    }
}
