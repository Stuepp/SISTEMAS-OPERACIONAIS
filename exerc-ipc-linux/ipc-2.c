#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int n = 1;

void X(){
    n = n * 16;
}

void Y(){
    n = n / 7;
}

void Z(){
    n = n + 40;
}

int main(void){
    pthread_t t1, t2, t3;
    int rc;
    rc = pthread_create(&t1, NULL, (void *)f1, NULL);
    rc = pthread_create(&t2, NULL, (void *)f2, NULL);
    rc = pthread_create(&t3, NULL, (void *)f3, NULL);
    rc = pthread_join(t1, NULL);
    rc = pthread_join(t2, NULL);
    rc = pthread_join(t3, NULL);
    printf("n=%d\n", n);
    return 0;
}
//gcc ipc-2.c -o ipc-2 -pthread
//for i in {1..500}; do ./ipc-2; done | sort | uniq