#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 3

int main(void){
  pid_t f[N], w;
  int status, i;

  for(i = 0; i< N; i++){
    f[i] = fork();
    printf("%i\n", i);
  }
  sleep(10);
  for(i = 0; i < N; i++){
    if(f[i] != 0)
      w = waitpid(f[i], &status, 0);
      printf("%i\n", i);
  }
  return 0;
}