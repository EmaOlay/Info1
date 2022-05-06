#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"

#define CANT ((int) 32)
#define ARCHIVO "prueba.txt"


int main() {
  FILE* f;
  int aux;
  char vector[CANT]="Adios!!!";
  //--abro el archivo--
  f=fopen(ARCHIVO,"a");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }

  //--Escribo
  aux= fwrite(vector,sizeof(char)*CANT,1,f);
  if (aux<0) {
    printf("Error al escribir en el archivo\n");
    return(-1);
  }else{
    printf("aux=%d\n",aux );
  }
  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
