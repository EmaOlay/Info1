#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"
#define CANT ((int) 2)


int main (void){
struct estudiante* p;
p=ingreso_estudiante(CANT);
ordenar_estudiante(p,CANT);
imprimir_estudiante(p,CANT);
liberar_estudiante(p,CANT);
return (0);
}
