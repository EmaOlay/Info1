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
  char vector[CANT];
  int edad_aux=0;

  struct data_S a;
  //--abro el archivo--
  f=fopen(ARCHIVO,"w");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //Pido ingreso de datos primera vez
  printf("Ingrese Nombre\n");
  scanf("%s", vector);
  printf("Ingrese Edad\n");
  scanf("%d", &edad_aux);
  while (edad_aux!=-1) {

    //asigno esos datos a la struct
    //Podria usar memoria dinamica pero no veo el sentido...
    a.edad=edad_aux;
    strcpy(a.nombre,vector);

    //--Escribo la struct a ver que pasa
    aux= fwrite(&a,1,sizeof(struct data_S),f);
    if (aux<0) {
      printf("Error al escribir en el archivo\n");
      return(-1);
    }

    /*
    //--Escribo nombre
    aux= fwrite(a.nombre,sizeof(char)*CANT,1,f);
    if (aux<0) {
      printf("Error al escribir en el archivo\n");
      return(-1);
    }
    //--Escribo edad
    aux= fwrite(&a.edad,sizeof(int),1,f);
    if (aux<0) {
      printf("Error al escribir en el archivo\n");
      return(-1);
    }
    */
    printf("Ingrese Nombre\n");
    scanf("%s", vector);
    printf("Ingrese Edad\n");
    scanf("%d", &edad_aux);
  }
  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
