#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, f2, f3, f4;

  printf("Processo principal (PID=%u)\n", getpid());
  f = fork();
  if(f == 0){//2º
    printf("B-");
    f3 =  fork();
    if(f3 == 0){//4º
      printf("D-");
      f4 = fork();
      if(f4 == 0){
        printf("\ndone\n");
      }else{
        printf("E");
      }
    }else{//3º
      printf("-C\n");
    }
  }else {// 1º
    printf("A\n");
    waitpid(f, NULL, 0);
  }
}