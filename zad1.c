#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define THREADS 10

void *PrintHello(void *id_thread)
{
    long tid;
    tid = (long)id_thread;
    printf("Hello SCR. Written by thread %ld!\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t dready[THREADS];
    int ret;
    long t;
    for (t = 0; t < THREADS; t++)
    {
        ret = pthread_create(&dready[t], NULL, PrintHello, (void *)t);
    }
    pthread_exit(NULL);
}