#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

/* Each thread will begin control in this function */
void *runner(void *param) {
    /* do some work ... */
    int* i = (int*) param;
    printf("RR: %d\n", *i);
    pthread_exit(0);
}


int main(int argc, char *argv[]) {
    int i, policy;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;
    /* get the default attributes */
    pthread_attr_init(&attr);
    /* get the current scheduling policy */
    if (pthread_attr_getschedpolicy(&attr, &policy) != 0)
        fprintf(stderr, "Unable to get policy.\n");
    else {
        if (policy == SCHED_OTHER)
            printf("SCHED OTHER\n");
        else if (policy == SCHED_RR)
            printf("SCHED RR\n");
        else if (policy == SCHED_FIFO)
            printf("SCHED FIFO\n");
    }
    /* set the scheduling policy - FIFO, RR, or OTHER */
    if (pthread_attr_setschedpolicy(&attr, SCHED_RR) != 0)
        fprintf(stderr, "Unable to set policy.\n");
    /* create the threads */
    for (i = 0; i < NUM_THREADS; i++) {
        int temp = i;
        pthread_create(&tid[i], &attr, runner, (void*)&temp);
    }
    /* now join on each thread */
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
