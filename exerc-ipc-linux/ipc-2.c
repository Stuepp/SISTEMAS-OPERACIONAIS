#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int n = 1;
pthread_cond_t cond1, cond2;
pthread_mutex_t mutex;
//ordem -> X -> Z -> Y
void X(){
    pthread_mutex_lock(&mutex);
    n = n * 16;
    pthread_cond_signal(&cond1);
    pthread_mutex_unlock(&mutex);
}

void Y(){
    pthread_mutex_lock(&mutex);
    while(n!=56)
        pthread_cond_wait(&cond2, &mutex);
    n = n / 7;
    pthread_mutex_unlock(&mutex);
}

void Z(){
    pthread_mutex_lock(&mutex);
    while(n!=16)
        pthread_cond_wait(&cond1, &mutex);
    n = n + 40;
    pthread_cond_signal(&cond2);
    pthread_mutex_unlock(&mutex);
}

int main(void){
    pthread_t t1, t2, t3;
    int rc;
    pthread_cond_init(&cond1, NULL);
    pthread_cond_init(&cond2, NULL);
    pthread_mutex_init(&mutex, NULL);
    rc = pthread_create(&t1, NULL, (void *)X, NULL);
    rc = pthread_create(&t2, NULL, (void *)Z, NULL);
    rc = pthread_create(&t3, NULL, (void *)Y, NULL);
    rc = pthread_join(t1, NULL);
    rc = pthread_join(t2, NULL);
    rc = pthread_join(t3, NULL);
    pthread_mutex_destroy(&mutex);
    printf("n=%d\n", n);
    return 0;
}
//gcc ipc-2.c -o ipc-2 -pthread
//for i in {1..500}; do ./ipc-2; done | sort | uniq