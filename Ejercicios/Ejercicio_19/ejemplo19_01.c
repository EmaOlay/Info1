#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* f;
  int aux;
  //--Abro el archivo--
  f=fopen("./prueba.txt","w");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //--Escribo--
  aux=fprintf(f, "Hola Mundo!!!\n");
  if (aux<0) {
    printf("Error al escribir en el archivo\n");
    return (-1);
  }
  //--cierro--
  aux=fclose(f);
  if (aux!=0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
