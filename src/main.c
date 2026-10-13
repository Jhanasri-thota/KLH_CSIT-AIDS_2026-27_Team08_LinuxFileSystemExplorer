#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/directory_operations.h"
#include "include/file_operations.h"
#include "include/file_info.h"
#include "include/process_operations.h"
#include "include/pipe_operations.h"
#include "include/fifo_operations.h"
#include "include/signal_operations.h"
#include "include/memory_operations.h"
#include "include/thread_operations.h"

void display_menu()
{
    printf("\n");
    printf("========================================\n");
    printf("     LINUX FILE SYSTEM EXPLORER\n");
    printf("========================================\n");
    printf("1.  List Directory\n");
    printf("2.  Create File\n");
    printf("3.  Write File\n");
    printf("4.  Read File\n");
    printf("5.  Create Directory\n");
    printf("6.  Remove Directory\n");
    printf("7.  View File Information\n");
    printf("8.  Delete File\n");
    printf("9.  Show Current Directory\n");
    printf("10. Change Directory\n");
    printf("11. File Position using lseek()\n");
    printf("12. Process Management\n");
printf("13. IPC - Pipe Communication\n");
printf("14. IPC - FIFO Communication\n");
printf("15. IPC - Signal Communication\n");
printf("16. Memory Management\n");
printf("17. Thread Synchronization\n");
printf("18. Exit\n");
    printf("========================================\n");
}

int main()
{
    int choice;

    char path[1024];
    char filename[1024];
    char content[4096];

    while (1)
    {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter directory path: ");
                scanf("%1023s", path);
                list_directory(path);
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%1023s", filename);
                create_file(filename);
                break;

            case 3:
                printf("Enter file name: ");
                scanf("%1023s", filename);

                printf("Enter content: ");
                getchar();

                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = '\0';

                write_file(filename, content);
                break;

            case 4:
                printf("Enter file name: ");
                scanf("%1023s", filename);
                read_file(filename);
                break;

            case 5:
                printf("Enter directory name: ");
                scanf("%1023s", path);
                create_directory(path);
                break;

            case 6:
                printf("Enter directory name: ");
                scanf("%1023s", path);
                remove_directory(path);
                break;

            case 7:
                printf("Enter file name: ");
                scanf("%1023s", filename);
                display_file_info(filename);
                break;

            case 8:
                printf("Enter file name: ");
                scanf("%1023s", filename);
                delete_file(filename);
                break;

            case 9:
                show_current_directory();
                break;

            case 10:
                printf("Enter directory path: ");
                scanf("%1023s", path);
                change_directory(path);
                break;

            case 11:
                printf("Enter file name: ");
                scanf("%1023s", filename);
                seek_file(filename);
                break;

            case 12:
{
    int process_choice;

    printf("\n========================================\n");
    printf("       PROCESS MANAGEMENT\n");
    printf("========================================\n");
    printf("1. Create Child Process\n");
    printf("2. Execute Command\n");
    printf("3. Wait for Child Process\n");
    printf("4. Back to Main Menu\n");
    printf("========================================\n");

    printf("Enter your choice: ");
    scanf("%d", &process_choice);

    switch (process_choice)
    {
        case 1:
            create_child_process();
            break;

        case 2:
            execute_command();
            break;

        case 3:
            wait_for_child_process();
            break;

        case 4:
            break;

        default:
            printf("Invalid process choice.\n");
    }

    break;
}

case 13:
    pipe_communication();
    break;

case 14:
    fifo_communication();
    break;

case 15:
    signal_communication();
    break;

case 16:
    memory_allocation_demo();
    break;

case 17:
    thread_synchronization_demo();
    break;

case 18:
    printf("\nExiting Linux File System Explorer...\n");
    return 0;
           default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
