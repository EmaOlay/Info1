#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handler_SIGALRM(int mySignal){
  printf("\n");
  printf("Hola Mundo\n");
}
void handler_SIGINT(int mySignal){
  alarm(5);
}

int main() {
int r;
struct sigaction s,pepe;
  //--Relleno la estructura sigaction--
  s.sa_handler = handler_SIGINT;
  s.sa_flags =0;
  sigemptyset(&s.sa_mask);
  r = sigaction(SIGINT, &s, NULL);
  if (r<0) {
    //--Error--
    printf("sigaction error: %d> %s\n",errno, strerror(errno) );
    return(-1);
  }

  //Reutilizo s en lugar de generar otra struct
  pepe.sa_handler = handler_SIGALRM;
  pepe.sa_flags =0;
  sigemptyset(&pepe.sa_mask);
  r = sigaction(SIGALRM, &pepe, NULL);
  while (1) {
    sleep(30);
  }

  return 0;
}
