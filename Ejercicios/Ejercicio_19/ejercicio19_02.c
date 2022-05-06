#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* f;
  int aux;
  //char buffer[80]="/home/ema/Desktop/emaolay/Lista anime.txt", *p;
  char buffer[80], *p;
  //Pregunto por la data para encontrar el archivo
  printf("Ingrese el path y archivo\n");
  p=fgets(buffer,sizeof(buffer),stdin);
  if(p==NULL){
    printf("Error leyendo path\n");
    return(-1);
  }
  //Limpio el caracter raro
  p=strchr(buffer,'\x0A');
  strcpy(p,"\0");
  //--Abro el archivo--
  f=fopen(buffer,"r");
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
