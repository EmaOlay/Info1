#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void handler_SIGCHLD (int mySignal){
  printf ("El hijo pid %d termino: SIGCHLD %d\r\n", wait (NULL),
  mySignal);
}
int main (void){
  int pid;
  int r;
  char mi_string[50];
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

  while (strcmp(mi_string,"Salir\n")!=0) {//Salir para Salir...
        //-- Padre --
        if (fgets(&mi_string[0],sizeof(mi_string)/sizeof(mi_string[0]),stdin)!=NULL) {
        write (myPipe[1], mi_string, strlen(mi_string));
        printf ("Padre> getpid: %d\r\n", getpid());
        printf ("Padre> getppid: %d\r\n", getppid());
        //close (myPipe[1]);//cierro?
        pid = fork();
        if (pid == -1 ) {
        //-- Error --
        printf ("Fork Error: %d> %s\r\n", errno, strerror(errno));
            }else {
               if (pid == 0) {
                 //-- Hijo --
                 printf ("Hijo> getpid: %d\r\n", getpid());
                 r = read (myPipe[0], &mi_string[0], 50);
                 if (r > 0) {
                   printf ("El hijo leyo de myPipe[0]-> %s\r\n", mi_string);
                   }
                 sleep(1);
                 return(0);
                 //close (myPipe[0]);//Es necesario cerrarlo?
                 }
            }
          }
          printf("%s\n",mi_string );
  }
  return (0);
}
