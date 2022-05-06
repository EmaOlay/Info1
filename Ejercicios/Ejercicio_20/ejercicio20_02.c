#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"

#define CANT ((int) 32)
#define ARCHIVO "prueba.txt"
int main() {
  FILE* f;
  int aux;
  char v[CANT], cantRead;

      //--abro el archivo--
      f=fopen(ARCHIVO,"r");
      if (f==NULL) {
        printf("Error al abrir el archivo\n");
        return(-1);
      }

      //--leo 1 byte
      cantRead=fread(&v[0],sizeof(v[0]),CANT, f);
      if (cantRead<0) {
        printf("Error al leer en el archivo\n");
        return(-1);
      }else{
        printf("Imprimo de a %ld byte en char\n", sizeof(v[0]));
        for (int i = 0; i < cantRead; i++) {
          printf("%c",v[i]);
        }
        printf("\n");
        printf("Imprimo de a %ld byte en hex\n", sizeof(v[0]));
        printHex(v,CANT);
      }
      rewind(f);

      //--leo 32 bytes
      cantRead=fread(&v[0],sizeof(v[0])*CANT,1, f);
      if (cantRead<0) {
        printf("Error al leer en el archivo\n");
        return(-1);
      }else{
        printf("Imprimo de a %ld byte en char\n", sizeof(v[0])*CANT);
        for (int i = 0; i < cantRead; i++) {
          printf("%s",v);
        }
        printf("\n");
        printf("Imprimo de a %ld byte en hex\n", sizeof(v[0])*CANT);
        printHex(v,CANT);
      }


      //--Cierro
      aux=fclose(f);
      if (aux!= 0) {
        printf("Error al cerrar el archivo\n");
      }

  return 0;
}
