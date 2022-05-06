
#include "funciones.c"


#define PATH "/home/ema/Desktop/emaolay/Final-2020-02-12"


int func (int fd, char *ip)
{
int tam_buffer=128;
char buffer[tam_buffer];
int rVal;
//Cosas para el dia y lo que pidieron
char nombre_aux[128];

    do {
        //-- Espero datos --
        printf ("Espero\r\n");
        rVal = TCP_read(buffer, 1, tam_buffer, fd);
        if (rVal != tam_buffer) {
            printf ("Error TCP_read\r\n");
            return (-2);
        }else{
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            //--Abro el archivo origen
              FILE* fp;
              sprintf (nombre_aux,"%s/data-%04d-%02d-%02d.log", PATH,tm.tm_year +1900, tm.tm_mon +1, tm.tm_mday);
              fp=fopen(nombre_aux,"w");
              if (fp==NULL) {
                printf("Error en fopen 1\n");
                return(-1);
              }
              //-- Lo escribo en el archivo que me dijeron --
              rVal = fwrite (buffer, tam_buffer, 1, fp);
              if (rVal < 0) {
              printf ("Error al escribir en el archivo\r\n");
              return (-1);
              }
              //-- Cierro el archivo --
              fclose(fp);
            return 0;
          }
        }
      while (1);
    return (0);
}


int main (void)
{
    //-- Inicio el server --
    printf ("Iniciando servidor\r\n");
    TCP_server ("8765", func);
    printf ("Finalizando instancia del servidor: %d\r\n", getpid());

    return (0);
}
