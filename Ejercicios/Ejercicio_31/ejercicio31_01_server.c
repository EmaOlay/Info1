#include <stdio.h>
#include "TCP_clientServer.h"

int func (int fd, char *ip)
{

int buffer=0;
int rVal;
//printf("ALGO\n");
    do {

        rVal = TCP_write(&buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_read: %s\r\n", ip);
            return (-1);
        }
        //buffer seria mi numero aleatorio...
        buffer++;
        sleep(1);
    } while ( buffer<10);
    return (0);
}

int main (void)
{
    //-- Inicio el server --
    printf ("Iniciando servidor\r\n");
    TCP_server ("5000", func);
    printf ("Finalizando instancia del servidor: %d\r\n", getpid());

    return (0);
}
