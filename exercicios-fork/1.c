#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, f2, f3;
  int letra = 65, d = 0;//abcd

  printf("Processo principal (PID=%u)\n", getpid());
  f = fork();
  if(f == 0){
    //do something
    //sleep(1);
    f2 = fork();
    if(f2 == 0){//2º ou 3º
      letra++;
      printf("B - %c\n", letra);
    } else{ //4º ou 3º
      f3 = fork();
      if(f3 == 0){
        letra++;
        printf("D - %c\n", letra);
      }else{ //3º ou 2º
        letra++;
        printf("C - %c\n", letra);
      }
    }
  } else { // pai 1º
    //do another 
    printf("A - %c\n", letra);
    waitpid(f, NULL, 0);
  }
  return 0;
}