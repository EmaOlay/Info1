#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"


int main (void){
struct persona* p;
p=ingreso_persona(CANT);
imprimir(p,CANT);
liberar(p,CANT);
return (0);
}
