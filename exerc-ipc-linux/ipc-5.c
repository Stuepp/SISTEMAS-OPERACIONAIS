#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int main( int argc, char *argv[ ] ){
  int Nthreads = (int)*argv[0];

  printf("%d\n", Nthreads);

  return 0;
}