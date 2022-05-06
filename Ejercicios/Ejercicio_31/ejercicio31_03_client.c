#include <stdio.h>
#include "TCP_clientServer.h"


#define ORIGEN "lista_anime.txt"
#define DESTINO "destino.txt"
int func(int fd, char *ip)
{
char buffer[128];
int rVal;
//--Abro el archivo origen
  FILE* fp1;
  fp1=fopen(ORIGEN,"r");
  if (fp1==NULL) {
    printf("Error en fopen 1\n");
    return(-1);
  }
//--Abro el archivo destino
  FILE* fp2;
  fp2=fopen(DESTINO,"w");
  if (fp2==NULL) {
    printf("Error en fopen 2\n");
    return(-1);
  }
    printf ("Conectado a: %s\r\n", ip);
    do {
        //--Leo el archivo
        if(fgets (buffer, sizeof (buffer), fp1)!=NULL){//--Lei algo valido entonces
          printf("buffer: %s\n", buffer);
          //Escribo al TCP
          rVal = TCP_write(buffer, 1, sizeof (buffer), fd);
          if (rVal != sizeof (buffer)) {
              printf ("Error TCP_write\r\n");
              return (-1);
          }
          //--Leo la respuesta
          rVal = TCP_read(buffer, 1, sizeof (buffer), fd);
          if (rVal != sizeof (buffer)) {
              printf ("Error TCP_read\r\n");
              return (-1);
          }
        /*printf ("Recibi de %s: %s\r\n\r\n", ip, buffer);
          printf("strlen(buffer): %ld\n", strlen(buffer));
          printf("buffer: %s\n", buffer);*/
          
          //--Escribo el otro archivo
          rVal = fwrite (buffer, strlen(buffer), 1, fp2);
          if (rVal < 0) {
          printf ("Error al escribir en el archivo\r\n");
          return (-1);
          }
        }

    //Condicion de salida
    } while (!feof(fp1));
//--Sali del while osea que termine de leer y escribir le mando la condicion
//de cierre al server
strcpy(buffer,"FIN");
rVal = TCP_write(buffer, 1, sizeof (buffer), fd);
if (rVal != sizeof (buffer)) {
    printf ("Error TCP_write\r\n");
    return (-1);
}
    return (0);
}

/**
	\fn int main (void)
	\brief Main que demuestra la creacion de un servidor.
    \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
    \date 2020.10.20
	\return void
*/
int main (void)
{
    //-- Inicio el server --
    printf ("Iniciando cliente\r\n");
    TCP_client ("127.0.0.1", "5000", func);
    printf ("Finalizando cliente\r\n");

    return (0);
}
