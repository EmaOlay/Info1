#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "1P_funciones.c"

int main() {

  //Ejercicio 01
  /*char string[]="El;perro;pepe;es;un;crack;";
  char corta[100];
  char larga[100];
  int cant;
  cant=tamanioPalabra(string,corta,larga);
  printf("La cantidad de palabras es: %d\n", cant);
  printf("La palabra mas corta es:%s\n",corta );
  printf("La palabra mas larga es: %s\n", larga);*/

  //Ejercicio 02
  char cuenta1[]="- 1.5/ - 1";
  char cuenta2[]="1 + 1";
  char cuenta3[]="2.5*5";
  char cuenta4[]="1/-1.25      ";
  char cuenta5[]="1!9";
  char cuenta6[]="-1.35/0";
  float resultado;
  printf("%s\n",cuenta1 );
  resultado=operacionesBasicas(cuenta1);
  printf("El resultado es:%g\n", resultado);
  printf("%s\n",cuenta2 );
  resultado=operacionesBasicas(cuenta2);
  printf("El resultado es:%g\n", resultado);
  printf("%s\n",cuenta3 );
  resultado=operacionesBasicas(cuenta3);
  printf("El resultado es:%g\n", resultado);
  printf("%s\n",cuenta4 );
  resultado=operacionesBasicas(cuenta4);
  printf("El resultado es:%g\n", resultado);
  printf("%s\n",cuenta5 );
  resultado=operacionesBasicas(cuenta5);
  printf("El resultado es:%g\n", resultado);
  printf("%s\n",cuenta6 );
  resultado=operacionesBasicas(cuenta6);
  printf("El resultado es:%g\n", resultado);
  return 0;
}
