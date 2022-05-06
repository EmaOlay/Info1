#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"

#define CANT ((int) 32)
#define ARCHIVO "./bDatos.bin"

struct data_S{
  char nombre[CANT];
  int edad;
};

int main() {
  FILE* f;
  int aux;
  int cantRead;
  struct data_S a;
  //--abro el archivo--
  f=fopen(ARCHIVO,"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }


  while (!feof(f)) {
    cantRead=fread(&a,1,sizeof(struct data_S), f);
    if (cantRead<=0) {
      printf("Error al leer en el archivo\n");
      return(-1);
    }else{
      printf("Nombre:%s\n", a.nombre);
      printf("Edad:%d\n", a.edad);
    }
   }
  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
