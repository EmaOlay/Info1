#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char const *argv[])
{
int rVal;
char buffer[80];
int fd;
int aux;
int contador=0;
    //--Reviso que esten usando bien el ejecutable--
    if (argc<3) {
      printf("Se usa:\n./guiaDeClase29_01_A detino.txt fifo1\n");
      return(-1);
    }
    //-- Creo el nodo fifo --
    rVal = mknod (argv[2], S_IFIFO | 0666, 0);
    if (rVal == -1) {
      perror ("Error mknod");
      //return (-1);
    }
    //-- Abro la fifo como lectura --
    printf ("Abro la FIFO como lectura\r\n");
    fd = open (argv[2], O_RDONLY);
    printf ("Espero datos para leer en la fifo\r\n");
    //-- Abro el archivo --
    FILE* fp;
    fp=fopen(argv[1],"w");
    if (fp==NULL) {
      printf("Error en fopen\n");
      return(-1);
    }
    while (1) {
      rVal = read (fd, buffer, sizeof (buffer));
      contador+=rVal;
      if (rVal > 0) {

        //-- Escribo --
        aux = fwrite (buffer, rVal, 1, fp);
        if (aux < 0) {
        printf ("Error al escribir en el archivo\r\n");
        return (-1);
        }
        //printf ("Recibi: %s", buffer);
      } else {
        if (rVal == 0) {
          printf ("Nadie escribe en la FIFO\r\n");
          printf("El contador vale:%d\n",contador );
          return (-1);
        }
      }
      printf ("Se Leyeron %d bytes en la FIFO\r\n", rVal);
    }

return (0);
}
