#include "funciones.c"

#define FIFO_NOMBRE "miFifo"

#define  ARCHIVO "/proc/loadavg"


int main() {
  int columnas=4;
  int mins=15;
  float mi_matriz[mins][columnas];
  int vector[mins][2];
  int indice_circ=0;
  float promedio[columnas-1];

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char buf[64];



  //levanto todo 1 vez
    for (int j = 0; j < mins; j++) {
      leer_parseo(ARCHIVO,mi_matriz[j],vector[j]);
      //printf("HOLA!@\n");
      /*
      for (int i = 0; i < columnas; i++) {
        printf("%f\t",mi_matriz[j][i] );
      }
      for (int i = 0; i < 2; i++) {
        printf("%d\t",vector[j][i] );
      }
      printf("\n");*/
      sleep(0.5);
    }


    int rVal;
    int fd;
        //-- Creo el nodo fifo --
        rVal = mknod (FIFO_NOMBRE, S_IFIFO | 0666, 0);
        if (rVal == -1) {
          perror ("Error mknod");
          //return (-1);
        }
        //-- Abro la fifo como Escritura --
        printf ("Abro la FIFO como Escritura\r\n");
        fd = open (FIFO_NOMBRE, O_WRONLY);

    while(1) {

      if ( ((indice_circ)%5) == 0 ) {
        printf("------------Promedio------------\n");

        printf ("Se escribieron %d bytes en la FIFO\r\n", rVal);
        for (int i = 0; i < columnas-1; i++) {
          promedio[i]= promedio_columna(&mi_matriz[0][i],columnas,mins);

          printf ("Se escribieron %d bytes en la FIFO\r\n", rVal);
          //printf("%f\t", promedio);
        }
        sprintf (buf,"%04d%02d%02d%2.2f%2.2f%2.2f", tm.tm_year +1900, tm.tm_mon +1, tm.tm_mday,promedio[0],promedio[1],promedio[2]);
        rVal = write (fd, buf, sizeof(buf));
        if (rVal > 0) {
          printf ("Mande: %s\t", buf);
        }
        printf("\n");
      }
      leer_parseo(ARCHIVO,mi_matriz[indice_circ],vector[indice_circ]);
      sleep(1);
      indice_circ++;
      if (indice_circ==mins) {
        indice_circ=0;
      }
    }

    close(fd);


  return 0;
}
