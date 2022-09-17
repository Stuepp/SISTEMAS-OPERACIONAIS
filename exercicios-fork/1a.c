#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, f2, f3;
  
  printf("Processor principal (PID=%u)\n", getpid());
  f = fork();
  if(f == 0){//filho de 1º
    printf("B-");
  }else{//1º
    printf("A\n");
    waitpid(f, NULL, 0);
    f2 = fork();
    if(f2 == 0){//filho de C-
      printf("D\n");
    }else{//filho do 1º?
      printf("C-");
    }
  }
}