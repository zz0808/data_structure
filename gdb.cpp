#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

void* pthread_run1(void* arg)
{
    (void)arg;

    while(1)
    {
        printf("I am thread1,ID: %d\n",pthread_self());
        i = 9;
        printf("I am thread1,ID: %d\n, i = %d",pthread_self(), i);
        sleep(1);
    }
}

void* pthread_run2(void* arg)
{
    (void)arg;

    while(1)
    {
        i = 10;
        printf("I am thread2,ID: %d\n",pthread_self());
        printf("I am thread2,ID: %d\n, i = %d",pthread_self(), i);

        sleep(1);
    }
}

void* pthread_run3(void* arg)
{
    (void)arg;

    while(1)
    {
        i = 11;

        printf("I am thread3,ID: %d\n",pthread_self());
        printf("I am thread3,ID: %d\n, i = %d",pthread_self(), i);

        sleep(1);
    }
}

void* pthread_run4(void* arg)
{
    (void)arg;

    while(1)
    {
        i = 14;

        printf("I am thread4,ID: %d\n",pthread_self());
        printf("I am thread4,ID: %d\n, i = %d",pthread_self(), i);

        sleep(1);
    }
}

int main()
{

    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;


    pthread_create(&tid1,NULL,pthread_run1,NULL);
    pthread_create(&tid2,NULL,pthread_run2,NULL);
    pthread_create(&tid3,NULL,pthread_run3,NULL);
    pthread_create(&tid4,NULL,pthread_run4,NULL);


    printf("I am main thread\n");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);


    return 0;
}
