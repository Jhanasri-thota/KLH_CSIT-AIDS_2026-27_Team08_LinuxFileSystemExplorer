#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "../include/pipe_operations.h"

void pipe_communication(void)
{
    int pipe_fd[2];
    pid_t pid;

    char message[] = "Hello from Parent Process!";
    char buffer[100];

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        return;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        close(pipe_fd[1]);

        read(pipe_fd[0], buffer, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';

        printf("\nChild Process received: %s\n", buffer);

        close(pipe_fd[0]);
    }
    else
    {
        close(pipe_fd[0]);

        write(pipe_fd[1], message, strlen(message) + 1);

        printf("\nParent Process sent: %s\n", message);

        close(pipe_fd[1]);

        wait(NULL);

        printf("Pipe communication completed.\n");
    }
}
