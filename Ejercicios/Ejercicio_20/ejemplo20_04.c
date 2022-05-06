#include <stdio.h>
#include <stdlib.h>

#define CANT ((int) 20)
#define ARCHIVO "./prueba.bin"
int main() {
  FILE* f;
  int aux;
  int v[CANT], cantRead;

      //--abro el archivo--
      f=fopen(ARCHIVO,"r");
      if (f==NULL) {
        printf("Error al abrir el archivo\n");
        return(-1);
      }

      //--Escribo
      cantRead=fread(&v[0],sizeof(v[0]),CANT, f);
      if (cantRead<0) {
        printf("Error al escribir en el archivo\n");
        return(-1);
      }else{
        printf("Cantidad de enteros leidos: %d\n", cantRead);
        for (int i = 0; i < cantRead; i++) {
          printf("%d\n",v[i]);
        }
      }

      //--Cierro
      aux=fclose(f);
      if (aux!= 0) {
        printf("Error al cerrar el archivo\n");
      }

  return 0;
}
