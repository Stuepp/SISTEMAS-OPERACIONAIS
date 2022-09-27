#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, f2, f3, f4;
  
  //printf("Processor principal (PID=%u)\n", getpid());
  printf("A\n");
  f = fork();
  if(f == 0){//filho de 1º
    printf("B-");
  }
  f2 = fork();
  if(f2 == 0){
    printf("C\n");
    f3 = fork();
    if(f3 == 0)
      printf("D-");
    f4 = fork();
    if(f4 == 0)
      printf("E\n");
  }
}
