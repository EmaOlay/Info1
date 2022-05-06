#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {

  char fecha[]="02-01-2020";
  //char fecha[]="02-02-2020";
  //char fecha[]="AA-AA-AAAA";
  //char fecha[]="020-220-20";
  //verifico tamanio
  if (strlen(fecha)!=10) {
    printf("Cantidad incorrecta de caracteres\n");
    return -1;
  }
  //quito guiones
  for (int i = 0; i < strlen(fecha); i++) {
    if (fecha[i]=='-') {
      //o memcpy
      memcpy(&fecha[i],&fecha[i+1],strlen(fecha)-i);
      //strncpy(&fecha[i],&fecha[i+1],strlen(fecha)-i);
    }
  }
  //Reviso numeros validos
  for (int i = 0; i < strlen(fecha); i++) {
    if (fecha[i]<'0' || fecha[i]>'9') {
      printf("La fecha tiene algo que no es num: %c\n",fecha[i]);
      return -2;
    }
  }
  //imprimo entero para veficicar visualmente
  for (int i = 0; i < strlen(fecha); i++) {
    printf("%c",fecha[i] );
  }
  printf("\n");
  //comparo primero y ultimo
  for (int i = 0; i < strlen(fecha)/2; i++) {
    if (fecha[i]==fecha[(strlen(fecha)-1)-i]) {
      //printf("fecha[%d]=%c, fecha[%d]=%c\n",i,fecha[i],(int)(strlen(fecha)-1)-i,fecha[(strlen(fecha)-1)-i]);
      printf("Correcto!,%d\n",i);
    }else{
      printf("fecha[%d]=%c, fecha[%d]=%c\n",i,fecha[i],(int)(strlen(fecha)-1)-i,fecha[(strlen(fecha)-1)-i]);
      printf("Incorrecto!,%d\n",i);
      return -3;
    }
  }
  return 0;
}
