#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define FIFO_NOMBRE "miFifo" //!< Nombre de la FIFO

int main (void)
{
int rVal;
char buffer[64];
int fd;
    //-- Creo el nodo fifo --
    rVal = mknod (FIFO_NOMBRE, S_IFIFO | 0666, 0);
    if (rVal == -1) {
      perror ("Error mknod");
      //return (-1);
    }
    //-- Abro la fifo como lectura --
    printf ("Abro la FIFO como lectura\r\n");
    fd = open (FIFO_NOMBRE, O_RDONLY);
    printf ("Espero datos para leer en la fifo\r\n");
    while (1) {
      rVal = read (fd, buffer, 64);
      if (rVal > 0) {
        printf ("%s\n", buffer);
      } else {
        if (rVal == 0) {
          printf ("Nadie escribe en la FIFO\r\n");
          return (-1);
        }
      }
      //printf ("Se Leyeron %d bytes en la FIFO\r\n", rVal);
    }
return (0);
}
