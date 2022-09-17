#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, f2, f3;

  printf("Processo principal (PID=%u)\n", getpid());
  f = fork();
  //else são os pais..? - aparentemente sim
  if(f == 0){
    f2 = fork();
    if(f2 == 0){
      f3 = fork();
      if(f3 == 0){//4º
        printf("D\n");
      }else{//3º
        printf("C\n");
      }
    }else{//2ª
      printf("B\n");;
    }
  } else { // pai 1º
    //do another 
    printf("A\n");
    waitpid(f, NULL, 0);
  }
  return 0;
}