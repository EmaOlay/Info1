#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>


void handler_SIGPIPE (int mySignal)
{
  printf ("No hay nadie leyendo en la FIFO %d\r\n", mySignal);
  exit (0);
}
int main(int argc, char const *argv[])
{
int rVal;
char buffer[80];
int fd;
int r;
int contador=0;
struct sigaction s;
  //--Reviso que esten usando bien el ejecutable--
  if (argc<3) {
    printf("Se usa:\n./guiaDeClase29_01_A origen.txt fifo1\n");
    return(-1);
  }
  //-- Relleno la estructura sigaction --
  s.sa_handler = handler_SIGPIPE;
  s.sa_flags = 0;
  sigemptyset(&s.sa_mask);
  r = sigaction (SIGPIPE, &s, NULL);
  if (r < 0) {
    //-- Error --
    printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));
    return (-1);
  }
  //-- Creo el nodo fifo --
  rVal = mknod (argv[2], S_IFIFO | 0666, 0);
  if (rVal == -1) {
    perror ("Error mknod");
    //return (-1);
  }
  //-- Abro la fifo como escritura --
  printf ("Abro la FIFO como escritura\r\n");
  fd = open (argv[2], O_WRONLY);
  //--Abro el archivo
    FILE* fp;
    fp=fopen(argv[1],"r");
    if (fp==NULL) {
      printf("Error en fopen\n");
      return(-1);
    }
  while (!feof(fp)) {

    if(fgets (buffer, sizeof (buffer), fp)!=NULL){
      rVal = write (fd, buffer, strlen (buffer)); //-- +1 para Tx el \0 --
      contador+=rVal;
      printf ("Se escribieron %d bytes en la FIFO\r\n", rVal);
    }

  }
  printf("El contador vale:%d\n",contador );
  return (0);
}
