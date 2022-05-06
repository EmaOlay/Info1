#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"


int main() {
  char vector[]="Hola Mundo!";
  printHex((void *)vector,sizeof(vector)/sizeof(char));
  return 0;
}
