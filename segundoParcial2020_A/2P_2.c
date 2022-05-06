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
#define NOT_MAYUS ((int) -1)
#define ENIE ((int) -2)
#define TAM_ALFABETO ((int) 25)
#define INDEX ((int) 26)
#define ERROR_D0 ((int) -3)
#define ERROR_D1 ((int) -4)
#define SIMBOLO_ENIE ((unsigned char)164)
#define SIMBOLO_ENIE2 ((unsigned char)165)

int rot_13 (char *dataPtr){
  //LA FUN SOLO ESTA DEFINIDA PARA MAYUS
  int i=0;
  int j=0;
  char tabla[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  while (*(dataPtr+i)!='\0') {
    /*if (strcmp((dataPtr+i),"Ñ")== 0) {
      return ENIE;
    }*/
    if ((*(dataPtr+i)<'A' || *(dataPtr+i)>'Z') && *(dataPtr+i)!=' ') {//no es mayus
      return NOT_MAYUS;
    }else{
      if (*(dataPtr+i)!=' ') {
        if (*(dataPtr+i)+13-'A' >TAM_ALFABETO) {//fuera de tabla

          *(dataPtr+i)=tabla[*(dataPtr+i)+13-INDEX-'A'];
        }else{
          *(dataPtr+i)=tabla[*(dataPtr+i)+13-'A'];
        }
        j++;
      }
    }
    i++;
  }
  return j;
}


int func (int fd, char *ip)
{
char buffer[TAM_BUFFER];
//tecnicamente con 5 veces mas largo seria suficiente
//porque mi definicion de la tabla tiene para una letra maximo 4 caracteres +\0
int rVal;
FILE* fp;
//--Abro el archivo

  //Como le paso el nombre sin variable global
  //O modificar TCP_Server
  fp=fopen("log.txt","w");
  if (fp==NULL) {
    printf("Error en fopen 1\n");
    return(-1);
  }
    do {

        //-- Espero palabra --
        printf ("Espero\r\n");
        rVal = TCP_read(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_read\r\n");
            return (-2);
        }

        //-- Le hago rot_13 --
        printf ("Recibi: %s\r\n", buffer);
        //escribo buffer por buffer
        fwrite(buffer,strlen(buffer),1,fp);
        fwrite("\r\n",strlen("\r\n"),1,fp);
        rot_13(buffer);
        printf("DESPUES: %s\n",buffer );
        //-- Lo envio de vuelta --
        rVal = TCP_write(buffer, 1, sizeof (buffer), fd);
        if (rVal != sizeof (buffer)) {
            printf ("Error TCP_write: %s\r\n", ip);
            return (-1);
        }

    } while (strcmp (buffer, "FIN\n") != 0);
    fclose(fp);
    return (0);
}

/**
	\fn int main (void)
	\brief Main que demuestra la creacion de un servidor.
    \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
    \date 2020.10.20
	\return void
*/
int main(int argc, char *argv[])
{
    if (argc!=3) {
      printf("El programa no se usa asi...\n");
    }else{
      printf("%s\n", argv[1]);
      //-- Inicio el server --
      printf ("Iniciando servidor\r\n");
      TCP_server (argv[1], func);
      printf ("Finalizando instancia del servidor: %d\r\n", getpid());
    }


    return (0);
}
