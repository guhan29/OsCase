#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
int shared=1;

void *fun1() {
    sem_wait(&mutex);
    printf("\n------Entered thread------\n");

    int x;
    x=shared;
    printf("Thread1 reads the value of shared variable as %d\n",x);
    x++;  //thread 1 increments its value
    printf("Local updation by Thread1: %d\n",x);
    sleep(1);  //thread 1 is preempted by thread 2
    shared=x; //thread 1 updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n",shared);

    printf("\n-----Exit thread-----\n");
    sem_post(&mutex);
}

void *fun2() {
    sem_wait(&mutex);
    printf("\n-----Entered thread-----\n");

    int y;
    y=shared;
    printf("Thread2 reads the value as %d\n",y);
    y--;  //thread 2 increments its value
    printf("Local updation by Thread2: %d\n",y);
    sleep(1);
    shared=y; //thread 2 updates the value of shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n",shared);

    printf("\n-----Exit thread-----\n");
    sem_post(&mutex);
}

// void* runner(void* arg) {
//     sem_wait(&mutex);
//     printf("Entered thread\n");
//     sleep(2);
//     count++;
//     printf("count: %d\n", count);
//     printf("\nExit thread\n");
//     sem_post(&mutex);
// }

int main() {
    sem_init(&mutex, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, fun1, NULL);
    sleep(2);
    pthread_create(&t2, NULL, fun2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    return 0;
}
