#include <stdio.h>
#include <pthread.h>

#include "../include/thread_operations.h"

int shared_counter = 0;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_counter(void *arg)
{
    int i;

    (void)arg;

    for (i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&counter_mutex);

        shared_counter++;

        pthread_mutex_unlock(&counter_mutex);
    }

    return NULL;
}

void thread_synchronization_demo(void)
{
    pthread_t thread1;
    pthread_t thread2;

    shared_counter = 0;

    printf("\n========================================\n");
    printf("     THREAD SYNCHRONIZATION\n");
    printf("========================================\n");

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 completed.\n");
    printf("Thread 2 completed.\n");
    printf("Final shared counter: %d\n", shared_counter);

    pthread_mutex_destroy(&counter_mutex);

    printf("Mutex synchronization completed.\n");
    printf("========================================\n");
}
