#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, w;
  int status;

  printf("Processo principal (PID=%u)\n", getpid());
  f = fork();
  if(f == 0){
    //do something
  } else {
    //do another something
  }
  return 0;
}