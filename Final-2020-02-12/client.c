#include "funciones.c"

#define ARCHIVO "/home/ema/Desktop/emaolay/lista_anime.txt"


int func(int fd, char *ip)
{
int tam_buffer=128;
char buffer[tam_buffer];
int rVal;

    printf ("Conectado a: %s\r\n", ip);
    //--Abro el archivo origen
      FILE* fp;

      fp=fopen(ARCHIVO,"r");
      if (fp==NULL) {
        printf("Error en fopen 1\n");
        return(-1);
      }
      rVal = fread (buffer, tam_buffer, 1, fp);
      if (rVal < 0) {
      printf ("Error al leer en el archivo\r\n");
      return (-1);
      }
      //-- Lo escribo en el archivo que me dijeron --
      rVal = TCP_write (buffer, tam_buffer, 1, fd);
      if (rVal < 0) {
      printf ("Error al escribir en el socket\r\n");
      return (-1);
      }
    fclose(fp);
    return (0);
}

int main (void)
{
    //-- Inicio el server --
    printf ("Iniciando cliente\r\n");
    TCP_client ("127.0.0.1", "8765", func);
    printf ("Finalizando cliente\r\n");

    return (0);
}
