#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define de consigna
#define CANT ((int) 10)
#define ARCHIVO "bDatos.txt"
#define NOMBRE_SIZE ((int) 32)
struct data_s{
  char nombre[NOMBRE_SIZE];
  unsigned int edad;
};

int main() {
  FILE* f;
  int aux, i=0;
  char nombre[NOMBRE_SIZE];
  int edad;
  struct data_s a[CANT];//por consigna el maximo es 10
  //--‌ ‌Abro‌ ‌el‌ ‌archivo‌ ‌--‌‌
  f=fopen(ARCHIVO,"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //--leo y guardo--
  while (!feof(f)) {
    aux=fscanf(f,"%[^,],%d\n",nombre,&edad);
    //check for error
    //printf("%d\n",aux );

    if(aux!=2){
      printf("Error el archivo tiene algo distinto a lo esperado\n");
      return(-2);
    }else{
      strcpy(a[i].nombre,nombre);
      a[i].edad=edad;
    }
  i++;
  }
  //Imprimo por pantalla
  for (int i = 0; i < CANT; i++) {
    printf("%s,%d\n",a[i].nombre, a[i].edad);
  }

  //--Cierro--
  aux=fclose(f);
  if (aux!=0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
