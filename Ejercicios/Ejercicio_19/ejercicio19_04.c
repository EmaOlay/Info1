#include <stdio.h>
#include <stdlib.h>

#define NOMBRE "bDatos.txt"
#define CANT ((int) 10)

int main() {
  FILE* f;
  int aux;
  char nombre[16];
  int edad;
  //--‌ ‌Abro‌ ‌el‌ ‌archivo‌ ‌--‌‌
  f=fopen(NOMBRE,"w");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //Pido nombres y edades
  for (int i = 0; i < CANT; i++) {
    printf("Ingrese el nombre:\n");
    scanf("%s", nombre);
    printf("Ingrese la edad\n");
    scanf("%d",&edad);
    aux=fprintf(f, "%s,%d\n",nombre ,edad);
    if (aux<0) {
      printf("Error al escribir en el archivo\n");
      return (-1);
    }
  }


  //--Cierro--
  aux=fclose(f);
  if (aux!=0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
