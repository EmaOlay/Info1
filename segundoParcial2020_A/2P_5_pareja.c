#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


#define SEGUNDOS ((int) 10)


void handler_SIGUSR1 (int mySignal)
{
  printf ("Hola signal %d\r\n", mySignal);
}
int main (void){
int r;
int segundos=0;
struct sigaction s;
//-- Relleno la estructura sigaction --
s.sa_handler = handler_SIGUSR1;
s.sa_flags = 0;
sigemptyset(&s.sa_mask);
r = sigaction (SIGUSR1, &s, NULL);
if (r < 0) {
  //-- Error --
  printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));
  return (-1);
  } else {
    printf ("Espero a SIGUSR1\r\n");
    while (1) {
      if (segundos<SEGUNDOS) {
        sleep (1);
        printf("pasaron %d segundos\n",segundos );
        segundos++;
      } else {
        segundos=0;
      }

    }
  }
return (0);
}
