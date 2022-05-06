#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "1P_funciones.c"

int main() {
  /*char Hexa1[]="0000";
  char Hexa2[]="0000";
  int a;
  a=hexaCmp(Hexa1,Hexa2);
  printf("El valor de a es:%d\n", a);*/

  /*char texto[]="Hola Mundo";
  char morse[200];
  decodificadorMorse(texto,morse);
  printf("%s\n",morse );*/
  char texto[200];
  char morse[]=".... --- .-.. .- -- ..- -. -.. --- ";
  codificadorMorse(morse,texto);
  printf("%s\n",texto);
  return 0;
}
