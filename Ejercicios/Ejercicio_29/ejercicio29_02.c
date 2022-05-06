#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
//Entiendo que escribo a argv[1] y leo desde argv[2]
void handler_SIGPIPE (int mySignal)
{
  printf ("No hay nadie leyendo en la FIFO %d\r\n", mySignal);
  exit (0);
}

void handler_SIGCHLD (int mySignal){
  printf ("El hijo pid %d termino: SIGCHLD %d\r\n", wait (NULL),
  mySignal);
}

int main(int argc, char const *argv[]) {
  char buffer[80];
  int rVal;
  int pid;
  int fd1;
  int fd2;
  struct sigaction s;
  //--Reviso que esten usando bien el ejecutable--
  if (argc<3) {
    printf("Se usa:\n./guiaDeClase29_02 fifo0 fifo1\nO en su defecto:\n./guiaDeClase29_02 fifo1 fifo0\n");
    return(-1);
  }
  //-- Relleno la estructura sigaction --
  s.sa_handler = handler_SIGPIPE;
  s.sa_flags = 0;
  sigemptyset(&s.sa_mask);
  rVal = sigaction (SIGPIPE, &s, NULL);
  if (rVal < 0) {
    //-- Error --
    printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));
    return (-1);
  }
  //-- Creo el nodo fifo --
  rVal = mknod (argv[1], S_IFIFO | 0666, 0);
  if (rVal == -1) {
    perror ("Error mknod");
    //return (-1);
  }
  //-- Creo el nodo fifo --
  rVal = mknod (argv[2], S_IFIFO | 0666, 0);
  if (rVal == -1) {
    perror ("Error mknod");
    //return (-1);
  }



  pid=fork();
  if (pid==-1) {
    printf("Error en el fork()\n");
    return(-1);
  }
  if (pid==0) {
    //-- Abro la argv[2] como Lectura --
    printf ("Abro la %s como Lectura\r\n",argv[2]);
    fd2 = open (argv[2], O_RDONLY);
    if (fd2<0) {
      printf("Error en el open\n");
      return(-1);
    }
  }else{
    //-- Abro la argv[2] como Escritura --
    printf ("Abro la %s como Escritura\r\n",argv[1]);
    fd1 = open (argv[1], O_WRONLY);
    if (fd1<0) {
      printf("Error en el open\n");
      return(-1);
    }
  }
  while (1) {
    if (pid==0) {
      //--hijo
      //--Leo la fifo argv[2]
      rVal = read (fd2, buffer, sizeof (buffer));
      if (rVal > 0) {
        printf("El hijo esta leyendo\n");
        printf ("De la %s vino: %s", argv[2],buffer);
      } else {
        if (rVal == 0) {
          printf ("Nadie esta escribiendo en la FIFO\r\n");
          return (-1);
        }
      }
    }else{
      //--Padre
      //--Escribo a la fifo argv[1]
      fgets (buffer, sizeof (buffer), stdin);
      rVal = write (fd1, buffer, strlen (buffer) + 1); //-- +1 para Tx el \0 --
      printf ("Se escribieron %d bytes en la %s\r\n", rVal,argv[1]);
    }
  }
  return 0;
}
