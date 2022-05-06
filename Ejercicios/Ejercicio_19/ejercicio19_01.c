#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* f;
  int aux;
  char buffer[80], *p;
  //--Abro el archivo--
  f=fopen("./ejercicio19_01.c","r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //--Imprimo--
  while (!feof(f)) {
    p=fgets(buffer,sizeof(buffer),f);
    if(p==NULL){
      printf("Error al leer el archivo\n");
      return(-2);
    }else{
      printf("%s",buffer);
    }
  }
  //--Cierro--
  aux=fclose(f);
  if (aux!=0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
