#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"
#define CANT ((int) 3)


int main (void){
struct persona* p;
p=ingreso(CANT);
//-- Imprimo la estructura --
for (int i = 0; i < CANT; i++) {
  printf ("Nombre: %s\r\n", (p +i)->nombre);
  printf ("Edad: %d\r\n", (p +i)->edad);
  printf ("Sexo: %c\r\n", (p +i)->sexo);
}
free(p);
return (0);
}
