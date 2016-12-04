#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;


void *lockAB(void *arg) {
    pthread_mutex_lock(&mutexA);
    int i;
    for (i=0;i<100000;i++) {}
    printf("Finished for loop in AB\n");
    pthread_mutex_lock(&mutexB);
    printf("Lock A->B\n");
    pthread_mutex_unlock(&mutexB);
    pthread_mutex_unlock(&mutexA);
    return NULL;
}

void *lockBA(void *arg) {
    pthread_mutex_lock(&mutexB);
    int i;
    for (i=0;i<100000;i++) {};
    printf("Finished for loop in BA\n");
    pthread_mutex_lock(&mutexA);
    printf("Lock B->A\n");
    pthread_mutex_unlock(&mutexA);
    pthread_mutex_unlock(&mutexB);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    int result;
    pthread_create(&p1, NULL, lockAB, NULL);
    pthread_create(&p2, NULL, lockBA, NULL);

    // join waits for the threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;
}