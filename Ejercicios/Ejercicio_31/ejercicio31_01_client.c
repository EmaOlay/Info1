#include <stdio.h>
#include "TCP_clientServer.h"

int func(int fd, char *ip)
{
int buffer;
int rVal;

    printf ("Conectado a: %s\r\n", ip);
    //Because it painted
    int variable_asd=1;
    //hasta el overflow me quedo en el while
    //que son mas de 10 seg
    while (variable_asd>0) {
      //-- Recibo mensaje de bienvenida --
      rVal = TCP_read(&buffer, 1, sizeof (buffer), fd);
      if (rVal != sizeof (buffer)) {
        printf ("Error TCP_read\r\n");
          return (-1);
      }
      variable_asd++;
      printf ("Numero %d\r\n", buffer);
    }



    return (0);
}

int main (void)
{
    //-- Inicio el server --
    printf ("Iniciando cliente\r\n");
    TCP_client ("127.0.0.1", "5000", func);
    printf ("Finalizando cliente\r\n");

    return (0);
}
