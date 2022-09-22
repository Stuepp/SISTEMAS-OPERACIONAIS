#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

  pthread_barrier_t barr;
  pthread_mutex_t mutex;
  long * fila;
  int pos = 0;
  int Nthreads;

void *newThread(void* p){
  for(int k = 0; k < 10; k++){
    pthread_barrier_wait(&barr);
    long i = (long)p;
    for(long n = 0; n < 1e9; n++){

    }
    pthread_mutex_lock(&mutex);
    fila[pos] = i;
    pos++;
    pthread_mutex_unlock(&mutex);
    if(pos == Nthreads){
      for(int j = 0; j < Nthreads; j++)
        printf("%ld ", fila[j]);
      putchar('\n');
      pos=0;
    }
  }
  //printf("Hello I'm thread number %ld\n", i);
}

int main( int argc, char *argv[ ] ){
  Nthreads = atoi(argv[1]);
  int rc;
  long i;
  pthread_t *trs = (pthread_t *) malloc(Nthreads * sizeof(pthread_t));
  pthread_barrier_init(&barr, NULL, Nthreads);
  pthread_mutex_init(&mutex, NULL);
  fila = (long *) malloc(Nthreads * sizeof(long));
  for(i = 0; i < Nthreads; i++){
    rc = pthread_create(&trs[i], NULL, (void *)newThread, (void*)i);
  }
  
  pthread_exit(NULL);
  return 0;
}