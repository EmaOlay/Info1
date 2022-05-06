#include <stdio.h>
#include <stdlib.h>
int * contarCaracteres (char *dataPtr){
int i=0;
int * dataCntPtr;
dataCntPtr = (int*)malloc (sizeof (*dataCntPtr) * 256);
if (dataPtr==NULL) {
  printf("Error al pedir memoria\n");
  return NULL;
}
  while (*(dataPtr+i)!='\0') {

    *(dataCntPtr + *(dataPtr+i))+=1;
    //printf("*(dataCntPtr + %d) = %d\n",*(dataPtr+i) , *(dataCntPtr + *(dataPtr+i)));
    i++;
  }
return dataCntPtr;
}

int main() {
int * vectorPtr;
char string[150];
char var;

printf("Ingrese un string\n");
scanf("%149[^\n]", string);
vectorPtr =contarCaracteres(string);
//Aca deberia revisar por NULL o no?
printf("Elegi una letra\n");
scanf("%c",&var );
scanf("%c",&var );
//printf("La letra que elegiste %c, tiene ascii %d\n", var,var);
printf("La cantidad de veces que se repitio tu letra(%c) fue:%d\n",var,*(vectorPtr+var));
free(vectorPtr);
  return 0;
}
