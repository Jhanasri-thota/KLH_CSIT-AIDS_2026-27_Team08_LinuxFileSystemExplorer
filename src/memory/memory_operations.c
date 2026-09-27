#include <stdio.h>
#include <stdlib.h>

#include "../include/memory_operations.h"

void memory_allocation_demo(void)
{
    int n;
    int *memory;

    printf("\n========================================\n");
    printf("       MEMORY MANAGEMENT\n");
    printf("========================================\n");

    printf("Enter number of integers to allocate: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid size.\n");
        return;
    }

    memory = (int *)malloc(n * sizeof(int));

    if (memory == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("\nMemory allocated successfully.\n");
    printf("Allocated memory: %ld bytes\n",
           (long)(n * sizeof(int)));

    for (int i = 0; i < n; i++)
    {
        memory[i] = i + 1;
    }

    printf("Stored values: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", memory[i]);
    }

    printf("\n");

    free(memory);

    printf("Memory released successfully.\n");
    printf("========================================\n");
}

