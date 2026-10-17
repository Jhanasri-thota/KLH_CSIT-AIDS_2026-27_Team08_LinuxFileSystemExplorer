#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#include "../include/signal_operations.h"

void signal_handler(int signal_number)
{
    printf("\nChild received signal: %d\n", signal_number);
    printf("Signal handled successfully.\n");
}

void signal_communication(void)
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
        signal(SIGUSR1, signal_handler);

        printf("\nChild process is waiting for a signal...\n");

        pause();

        printf("Child process completed signal handling.\n");

        exit(0);
    }
    else
    {
        sleep(1);

        printf("\nParent sending SIGUSR1 to child...\n");

        kill(pid, SIGUSR1);

        wait(NULL);

        printf("Signal communication completed.\n");
    }
}
