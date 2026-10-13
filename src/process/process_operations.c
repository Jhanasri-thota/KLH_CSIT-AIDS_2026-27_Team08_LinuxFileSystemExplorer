#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/process_operations.h"

void create_child_process(void)
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        printf("\nChild Process Created\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else
    {
        printf("\nParent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        wait(NULL);

        printf("Child process completed.\n");
    }
}

void execute_command(void)
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        printf("\nExecuting ls command...\n");

        execlp("ls", "ls", "-l", NULL);

        perror("exec");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
        printf("Command execution completed.\n");
    }
}

void wait_for_child_process(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        printf("\nChild process is running...\n");
        sleep(2);
        printf("Child process finished.\n");
        exit(0);
    }
    else
    {
        printf("Parent is waiting for child process...\n");

        waitpid(pid, &status, 0);

        printf("Parent received child completion.\n");
    }
}

