#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, w;
  int status = 0;

  printf("Processo principal (PID=%u)\n", getpid());
  f = fork();
  if(f == 0){
    //do something
    sleep(1);
    printf("%i\n", status);
    status++;
    exit(0);
  } else {
    //do another 
    printf("A\n");
  }
  return 0;
}