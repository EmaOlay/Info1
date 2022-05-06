#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"

#define CANT ((int) 10)
#define ARCHIVO "entero.bin"


int main() {
  FILE* f;
  int aux;

  //--abro el archivo--
  f=fopen(ARCHIVO,"w");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }

  //--Escribo
  for (int i = 0; i < CANT; i++) {
    aux= fwrite(&i,sizeof(int),1,f);
    if (aux<0) {
      printf("Error al escribir en el archivo\n");
      return(-1);
    }else{
      printf("Escribi bien,%d\n",i );
    }
  }

  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
