#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[]) {
int r;
  if (argc!=3) {
    printf("El programa no se usa asi...\n");
  }else{
    while (1) {
      sleep (atoi(argv[1]));
      r=kill(atoi(argv[2]), SIGUSR1);
      if (r != 0) {
        printf("Error al hacer kill\n");
        return (-1);
      }
    }
  }
  return 0;
}
