#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define FIFO_NOMBRE "miFifo"
//!< Nombre de la FIFO
void handler_SIGPIPE (int mySignal)
{
  printf ("No hay nadie leyendo en la FIFO %d\r\n", mySignal);
  exit (0);
}
int main (void)
{
int rVal;
char buffer[32];
int fd;
int r;
struct sigaction s;
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
  rVal = mknod (FIFO_NOMBRE, S_IFIFO | 0666, 0);
  if (rVal == -1) {
    perror ("Error mknod");
    //return (-1);
  }
  //-- Abro la fifo como escritura --
  printf ("Abro la FIFO como escritura\r\n");
  fd = open (FIFO_NOMBRE, O_WRONLY);
  printf ("Espero datos para escribir en la fifo\r\n");
  while (1) {
    fgets (buffer, sizeof (buffer), stdin);
    rVal = write (fd, buffer, strlen (buffer) + 1); //-- +1 para Tx el \0 --
    printf ("Se escribieron %d bytes en la FIFO\r\n", rVal);
  }
  return (0);
}
