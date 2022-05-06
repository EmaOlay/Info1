#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handler_SIGALRM(int mySignal){
  printf("\n");
  printf("Call Me By Your Name\n");
}
void handler_SIGINT(int mySignal,int b){
  alarm(b);
}

int main() {
  int r;
  int tiempo=0;
  struct sigaction s;
    //--Relleno la estructura sigaction--
    s.sa_handler = handler_SIGALRM;
    s.sa_flags =0;
    sigemptyset(&s.sa_mask);
    r = sigaction(SIGALRM, &s, NULL);
//podria quitar el while para no llamar a alarm todo el Tiempo

    while (1) {
      int tiempo=0;
      printf("Tiempo?\n");
      scanf("%1d",&tiempo );
      alarm(tiempo);
    }
  return 0;
}
