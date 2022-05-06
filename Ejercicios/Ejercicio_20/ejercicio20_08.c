#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define ARCHIVO "/home/ema/Desktop/emaolay/Ejercicios/Ejercicio_20/20_07.txt"

int main() {
  FILE* f;
  int aux,cantRead;
  char c;
  struct stat a;
  //--abro el archivo--
  f=fopen(ARCHIVO,"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  /*
  //--Leo de a 1 byte para saber la cantidad total de bytes
  while (!feof(f)) {
    cantRead=fread(&c,1,sizeof(c), f);
    if (cantRead<0) {
      printf("Error al leer en el archivo\n");
      return(-1);
    }else{
      i++;
    }
   }
   */
   stat(ARCHIVO,&a);
  //-- Me vuelvo a parar en 0 pero entiendo que no es necesario...
  //rewind(f);
  printf("%ld\n", a.st_size);
  //-- Me adelanto la mitad de bytes desde el principio;
  fseek(f, a.st_size/2,SEEK_SET);
  //--Imprimo en Hexa
  while (!feof(f)) {
    cantRead=fread(&c,1,sizeof(c), f);
    if (cantRead<0) {
      printf("Error al leer en el archivo\n");
      return(-1);
    }else{
      printf("%c", c);
    }
   }
  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
