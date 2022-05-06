#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"
#define CANT ((int) 2)


int main (void){
struct estudiante* p;
p=ingreso_estudiante(CANT);

for (int i = 0; i < CANT; i++) {
  printf("Nombre: %s\n", (p+i)->nombre);
  printf("Cantidad de Finales del Estudiante:%d\n", (p+i)->cantFinales);
  for (int j = 0; j < (p+i)->cantFinales; j++) {
    printf("Materia:%s\n", (p+i)->final[j].materia);
    printf("Nota:%d\n", (p+i)->final[j].nota);
  }
}
for (int i = 0; i < CANT; i++) {//tengo tantos punteros a finales como personas
  free((p+i)->final);
}
free(p);
return (0);
}
