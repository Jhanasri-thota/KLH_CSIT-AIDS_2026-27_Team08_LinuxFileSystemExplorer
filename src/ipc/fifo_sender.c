#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define FIFO_NAME "ossp_chat_fifo"

int main()
{
    char message[1024];
    int fd;

    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        /* FIFO may already exist */
    }

    printf("FIFO Sender Started\n");
    printf("Enter message: ");

    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    fd = open(FIFO_NAME, O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, message, strlen(message) + 1);

    printf("\nMessage sent successfully!\n");

    close(fd);

    return 0;
}
