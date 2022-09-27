#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){ // olhar zap F312 -> foto do quadro contém resposta
  pid_t f1, f2;

  f1 = fork();
  if(f1 != 0){
    f2 = fork();
    if(f2 == 0){
      puts("F");
      puts("P");
    } else{
      puts("R");
      puts("Z");
    }
  } else{
    puts("S");
    puts("Q");
  }
  return 0;
}

// RZ -> SQ -> FP 1
// RZ -> FP -> SQ 2
// SQ -> RZ -> FP 3
// SQ -> FP -> RZ 4
// FP -> RZ -> SQ 5
// FP -> SQ -> RZ 6