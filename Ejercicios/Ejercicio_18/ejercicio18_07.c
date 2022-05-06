#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"
#define CANT ((int) 2)


int main (void){
struct estudiante* p;
p=ingreso_estudiante(CANT);
imprimir_estudiante(p,CANT);
for (int i = 0; i < CANT; i++) {//tengo tantos punteros a finales como personas
  free((p+i)->final);
}
free(p);
return (0);
}
