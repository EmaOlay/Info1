#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "1P_funciones.c"

int main() {
  //Ejercicio 1
  /*char string[]="Hola Mundo";
  int a;
  a=invertir(string);
  printf("Y el largo del string es: %d\n", a);
  printf("%s\n",string );*/
  //Ejercicio 2
  /*
  int vector1[]={1,3,5,7,9};
  int vector2[]={0,2,4,6,8};
  int resultado[10];
  int a;
  //printf("%d\n",sizeof(vector1)/sizeof(int) );
  a=mezclar(vector1,(int)sizeof(vector1)/sizeof(int),vector2,(int)sizeof(vector2)/sizeof(int),resultado);
  for (int i = 0; i < 10; i++) {
    printf("%d ",resultado[i] );
  }
  printf("\n\r");
  printf("El resultado tiene de largo: %d\n", a);*/
  //Ejercicio 3
  char numero[32];
  strcpy(numero,"-   001.   27");
  printf("El numero es: %g\n", asciiToFloat(numero));
  //printf("El numero es: %g\n", asciiToFloat("1.27"));
  return 0;
}
