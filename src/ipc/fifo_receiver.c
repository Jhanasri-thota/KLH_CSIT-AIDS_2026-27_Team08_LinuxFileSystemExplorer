#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "ossp_chat_fifo"

int main()
{
    char buffer[1024];
    int fd;

    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        /* FIFO may already exist */
    }

    printf("FIFO Receiver Started\n");
    printf("Waiting for message from sender...\n");

    fd = open(FIFO_NAME, O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';

        printf("\n========================================\n");
        printf("        MESSAGE RECEIVED\n");
        printf("========================================\n");
        printf("%s\n", buffer);
        printf("========================================\n");
    }

    close(fd);
    unlink(FIFO_NAME);

    return 0;
}

