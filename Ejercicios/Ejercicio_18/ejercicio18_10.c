#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"
#define CANT ((int) 2)

int main (void){
struct finales mimi[3]={{"Info1",8},{"Info2",7},{"AM1",9}};
struct finales emanuel[2]={{"Info1",10},{"Info2",10}};
struct estudiante p[CANT]={{"Mimi",3,mimi},{"Emanuel",2,emanuel}};
/*char nombre[16];
char materia[16];
p=ingreso_estudiante(CANT);
printf("Ingrese el alumno a buscar:\n");
scanf("%s",&nombre[0]);
printf("Ingrese la materia a buscar:\n");
scanf("%s",&materia[0]);
int nota_adquirida=buscar(p,CANT,nombre,materia);
*/
int nota_adquirida=buscar(p,CANT,"Mimi","Info2");
printf("La nota encontrada fue:%d\n",nota_adquirida );
//liberar_estudiante(p,CANT);
return (0);
}
