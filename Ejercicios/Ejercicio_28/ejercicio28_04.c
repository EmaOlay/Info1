#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


#define  HIJOS_CANT ((int) 5)
#define  NUM_CANT ((int) 10)

void handler_SIGCHLD (int mySignal){
  printf ("El hijo pid %d termino: SIGCHLD %d\r\n", wait (NULL),
  mySignal);
}
int main (void){
  int pid;
  int r;
  int numero_random=0;
  struct sigaction s;
  int myPipe[2]; // 0: Usado para leer. 1: Usado para escribir.
  //-- Relleno la estructura sigaction --
  s.sa_handler = handler_SIGCHLD;
  s.sa_flags = 0;
  sigemptyset(&s.sa_mask);
  r = sigaction (SIGCHLD, &s, NULL);
  if (r < 0) {
  //-- Error --
  printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));
  return (-1);
  }
  r = pipe(myPipe);
  if (r < 0) {
  //-- Error --
  printf ("pipe error: %d> %s\r\n", errno, strerror(errno));
  return (-2);
  }

  //---
  //Empieza el programa
  //---

  for (int i = 0; i < HIJOS_CANT; i++) {
    pid = fork();
    if (pid==0) {
      //--hijo
      srandom(getpid()+getppid());
      for (int i = 0; i < NUM_CANT; i++) {
        numero_random=random()%100;
        write (myPipe[1], &numero_random, sizeof(numero_random));
        sleep(1);
      }
      return(0);
    }
  }
  for (int i = 0; i < HIJOS_CANT*NUM_CANT; i++) {
    //--Padre
    r = read (myPipe[0], &numero_random, sizeof(numero_random));
    if (r > 0) {
      printf ("El Padre leyo de myPipe[0]-> %d\r\n", numero_random);
      printf("%d\n",i );
      }
  }
  return(0);
}
