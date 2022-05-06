#include <stdio.h>
#include "TCP_clientServer.h"

int func(int fd, char *ip)
{
char buffer[128];
int rVal;

    printf ("Conectado a: %s\r\n", ip);
    do {
        //pido se ingrese algo que voy a guardar en buffer
        printf("Ingrese una frase a codificar\n");
        fgets(&buffer[0],sizeof (buffer),stdin);

        //lo mando al server
        rVal = TCP_write(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_write\r\n");
            return (-1);
        }
        //espero la respuesta del server
        rVal = TCP_read(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_read\r\n");
            return (-1);
        }
        //Imprimo por pantalla
        printf ("Recibi de %s: %s\r\n\r\n", ip, buffer);
        //Condicion de salida
        if (strcmp (buffer, "FIN\n") == 0) {
            printf ("Recibi comando de salida.\r\n");
            return (-1);
        }
    } while (1);

    return (0);
}

/**
	\fn int main (void)
	\brief Main que demuestra la creacion de un servidor.
    \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
    \date 2020.10.20
	\return void
*/
int main (int argc, char *argv[])
{
  if (argc!=3) {
    printf("El programa no se usa asi...\n");
  }else{
    //-- Inicio el server --
    printf ("Iniciando cliente\r\n");
    TCP_client (argv[1], argv[2], func);
    printf ("Finalizando cliente\r\n");
  }
    return (0);
}
