#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>



int dividirArchivos(char *nombre, int tamanio){
struct stat buffer;
int aux=0;
float cant_archivos;
char nombre_destino[128];
char* ptr;
FILE* fp_dest;
int cant_leida=0;
int diff_cant=0;
ptr=(char*)malloc(sizeof(*ptr)*tamanio);
  //--Abro el archivo
    FILE* fp;
    //nombre es un char *
    fp=fopen(nombre,"r");
    if (fp==NULL) {
      printf("Error en fopen 1\n");
      return(-1);
    }
  //Guardo el tamanio del archivo para verificaciones
  aux=stat(nombre,&buffer);
  if (aux== -1) {
    printf("Error al obtener informacion sobre el archivo\n");
    //Este error no esta definido en la consigna lo creo yo...
    return(-5);
    }
  //printf("El tamanio del archivo es: %ld\n", buffer.st_size);
  //Hago las cuentas para despues separar el ARCHIVO
  cant_archivos=ceil((float)buffer.st_size/tamanio);
  printf("cantidad de archivos=%g\n", cant_archivos);
  //Hasta aca tengo la cantidad de archivos
  if (cant_archivos>999) {
   printf("Cantidad de archivos mayor a 999\n");
   return (-2);
  }
  //Preguntar
  if (cant_archivos==0) {
    printf("Cantidad de archivos es 0\n");
    return (-3);
  }

  for (int i = 0; i < cant_archivos; i++) {
    sprintf(nombre_destino,"%s.%.3d",nombre, i);
    //printf("str contiene: %s\n",str );
    //--Abro los archivos destino
      //nombre destino es un char *
      fp_dest=fopen(nombre_destino,"w");
      //Piso es fp con algo nuevo cada vuelta
      if (fp_dest==NULL) {
        printf("Error en fopen %d\n",i);
        return(-1);
      }
      diff_cant=buffer.st_size-cant_leida;
      //Este if que viene es porque fread corta si le decis de leer de mas y tira error...
      //Si la cantidad por leer es mayor a tamnio leo el tamnio
      if ((diff_cant)>tamanio) {
        if (fread(ptr, tamanio,1, fp)>0) {
          //printf("archivo %d: %s\n",i,ptr );
          fwrite(ptr,tamanio,1,fp_dest);
        }
      cant_leida+=tamanio;
      }else{//Leo menos cantidad
        if (fread(ptr, diff_cant,1, fp)>0) {
          //printf("archivo %d: %s\n",i,ptr );
          fwrite(ptr,diff_cant,1,fp_dest);
        }
      }

      fclose(fp_dest);
  }
  fclose(fp);
  return(0);
}
