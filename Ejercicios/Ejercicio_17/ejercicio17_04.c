#include <stdio.h>
//Probalo con esto amiguin
/*Tres tristes tigres,
tragaban trigo en un trigal,
en tres tristes trastos,
tragaban trigo tres tristes tigres.*/
void contarCaracteres (char *dataPtr, int *dataCntPtr){
int i=0;
  while (*(dataPtr+i)!='\0') {

    *(dataCntPtr + *(dataPtr+i))+=1;
    //printf("*(dataCntPtr + %d) = %d\n",*(dataPtr+i) , *(dataCntPtr + *(dataPtr+i)));
    i++;
  }
}

int main() {
int vector[256];
char string[150];
char var;
//Me aseguro que vector no tenga basura...
for (int i = 0; i < 256; i++) {
  vector[i]=0;
}

printf("Ingrese un string\n");
scanf("%s", string);
contarCaracteres(string,vector);
printf("Elegi una letra\n");
scanf("%c",&var );
scanf("%c",&var );
//printf("La letra que elegiste %c, tiene ascii %d\n", var,var);
printf("La cantidad de veces que se repitio tu letra(%c) fue:%d\n",var,vector[(int)var]);
  return 0;
}
