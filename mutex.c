#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t tid[2];
int count;
pthread_mutex_t mutex;
  
void* fun(void* arg) {
    pthread_mutex_lock(&mutex);
  
    unsigned long i = 0;
    count += 1;
    printf("\n Process %d has started\n", count);
  
    sleep(3);
  
    printf("\n Process %d has finished\n", count); 
    pthread_mutex_unlock(&mutex);
  
    return NULL;
}
  
int main() {
    int i = 0;
    int error;
  
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
  
    for(i=1; i<=2; i++) {
        error = pthread_create(&(tid[i]), NULL, &fun, NULL);
        if (error != 0)
            printf("\nThread can't be created :[%s]", strerror(error));
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&mutex);
  
    return 0;
}
