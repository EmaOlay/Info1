#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_CONSIGNA ((int) 4)
#define ARCHIVO "/home/ema/Desktop/emaolay/Ejercicios/Ejercicio_22/22_05.txt"
int leerTexto (char* nombre, char** textoPtr){
  FILE* f;
  int j=0,i=0;
  int aux;//guardo las posiciones de coincidencia
  char linea[255];
  //--abro el archivo--
  f=fopen(nombre,"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //leo cuantas veces haga falta
  /*
  while(!feof(f)){
    j=0;
    //verifico que leyo bien
    if(fgets(linea,sizeof(linea),f) != NULL){
      printf("Lei bien!\n");
      while (linea[j]!='\0') {
        printf("%c",linea[j] );
      //si da verdadero lei bien y encontre un separador
        if(strstr(&linea[j],"\r\n")==&linea[j]){
          printf("coincidencia!\n");
          *(textoPtr + i)=(char*) malloc(sizeof(char)*j);
          //esto es una boludes pero uso el n coppy para no meter el \r\n
          strncpy(*(textoPtr + i),&linea[0],(j-sizeof("\r\n")));
          j+=sizeof("\r\n");
          i++;
        }
        j++;
      }
    }
    printf("aca?\n");
  }
  */

  for (int i = 0; i < CANT_CONSIGNA -1; i++) {//por consigna se que son 4 lineas
    fgets(linea,sizeof(linea),f);
    *(textoPtr + i)=(char*) malloc(sizeof(char)*strlen(linea));
    if (*(textoPtr + i)==NULL) {
      printf("Error al pedir memoria,%d\n",i);
      return(-1);
    }
    strcpy(*(textoPtr + i),linea);
  }

  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}

int main() {
  char* lineas[CANT_CONSIGNA];
  for (int i = 0; i < CANT_CONSIGNA; i++) {
    *(lineas + i)=NULL;
  }
  leerTexto(ARCHIVO, lineas);
  for (int i = 0; i < CANT_CONSIGNA; i++) {
    printf("%s\n",*(lineas + i) );
  }
  return 0;
}
