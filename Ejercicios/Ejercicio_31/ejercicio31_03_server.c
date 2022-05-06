/**
	\file TCP_serverMain.c
	\brief Ejemplo de uso del servidor TCP
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.30
*/
#include <stdio.h>
#include "TCP_clientServer.h"

/**
	\fn int func (int fd, char *ip)
	\brief Funcion que maneja la conexion con un cliente.
  \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
  \date 2020.10.20
  \param fd File descriptor de la conexion.
  \param ip PUntero que contiene la IP del cliente conectado.
	\return void
*/
int func (int fd, char *ip)
{
char buffer[128];
int rVal;

    do {
        //-- Espero palabra --
        printf ("Espero\r\n");
        rVal = TCP_read(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_read\r\n");
            return (-2);
        }

        //-- Lo paso a mayuscula --
        printf ("Recibi %s\r\n", buffer);
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = toupper(buffer[i]);
        }

        //-- Lo envio de vuelta --
        rVal = TCP_write(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_write: %s\r\n", ip);
            return (-1);
        }

    } while (strcmp (buffer, "FIN") != 0);
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
    printf ("Iniciando servidor\r\n");
    TCP_server ("5000", func);
    printf ("Finalizando instancia del servidor: %d\r\n", getpid());

    return (0);
}
