#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t f, f2, f3;

  //printf("Processo principal (PID=%u)\n", getpid());
  printf("A\n");
  f = fork();
  //else são os pais..? - aparentemente sim
  if(f == 0){
    printf("B\n");
    f2 = fork();
    if(f2 == 0){
      printf("C\n");
      f3 = fork();
      if(f3 == 0)
        printf("D\n");
    }
  }
  return 0;
}