#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"

#define ARCHIVO "entero.bin"


int main() {
  FILE* f;
  int aux,i=0,cantRead;
  int* ptr=NULL;
  int* ptrBack;
  //--abro el archivo--
  f=fopen(ARCHIVO,"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }

  //--Leo suponiendo que no se que esta adentro
  while (!feof(f)) {
    ptrBack = (int*)realloc (ptr,sizeof(*ptr)*(i+1));
    if (ptrBack==NULL) {
      printf("Error al pedir memoria\n");
      return(-1);
    }else{
      ptr=ptrBack;
    }
    cantRead=fread(ptr+i,sizeof(*ptr),1, f);
    if (cantRead<0) {
      printf("Error al leer en el archivo\n");
      return(-1);
    }
    i++;
  }
  //i-1 xq hace un ++ de mas
  printf("Imprimo en dec\n");
  for (int j = 0; j < i-1; j++) {
    printf("%d\n",*(ptr+j) );
  }
  printf("Imprimo en Hex\n");
  for (int j = 0; j < i-1; j++) {
    printf("%x\n",*(ptr+j) );
  }
  free(ptr);
  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
