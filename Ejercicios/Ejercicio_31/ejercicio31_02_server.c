/**
	\file TCP_serverMain.c
	\brief Ejemplo de uso del servidor TCP
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.30
*/
#include <stdio.h>
#include "TCP_clientServer.h"

#define  TAM_BUFFER ((int) 128)

/**
	\fn int func (int fd, char *ip)
	\brief Funcion que maneja la conexion con un cliente.
    \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
    \date 2020.10.20
    \param fd File descriptor de la conexion.
    \param ip PUntero que contiene la IP del cliente conectado.
	\return void
*/
//--Este es el codificador que hice como practica para el PrimerPArcial2019
//Tiene pinta de andar no recuerdo que tuviera algun problema grave...
int decodificadorMorse (char *texto, char *morse){
  int i=0;
  char aux;
  char *tabla[]={".- ",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--..",
};
*(morse+0)='\0';

  while (*(texto+i)!='\0') {

    aux=tolower(*(texto+i));
    //printf("%c\n", *(texto+i));
    if ((aux>='a' && aux<='z') || aux==' ' ) {
      if (aux==' ') {
        strcat(morse," ");
      }else{
      strcat(morse,tabla[aux-'a']);
      }
    }else{

      printf("No es letra min\n");
      return (-1);
    }
    i++;
  }
  return 0;
}


int func (int fd, char *ip)
{
char buffer[TAM_BUFFER];
//tecnicamente con 5 veces mas largo seria suficiente
//porque mi definicion de la tabla tiene para una letra maximo 4 caracteres +\0
char morse[TAM_BUFFER];
int rVal;

    do {
        //-- Espero palabra --
        printf ("Espero\r\n");
        rVal = TCP_read(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_read\r\n");
            return (-2);
        }

        //-- Lo paso a morse --
        printf ("Recibi: %s\r\n", buffer);
        //Antes de decodificarlo lo limpio para que no le quede nada adentro
        //En caso de que me manden palabras largas y despues palabras cortas
        for (int i = 0; i < TAM_BUFFER; i++) {
          morse[i]='\0';
        }
        printf("ANTES: %s\n",morse );
        //morse=&morse[0] lo mismo para buffer
        decodificadorMorse (buffer, morse);
        printf("DESPUES: %s\n",morse );
        //-- Lo envio de vuelta --
        rVal = TCP_write(morse, 1, sizeof (morse), fd);
        if (rVal != sizeof (morse)) {
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
