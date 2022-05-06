#include <stdio.h>
#include <stdlib.h>


#define CANT ((int) 5)
/*
Olay Emanuel
Leg:1568656
gcc -Wall 1PE_01.c -o 1PE_01.out
*/

int verificarVect(int* dataPtr, int dataCant){
  int aux;
  int ascendente=0;
  int descendente=0;
  int* dataPtr_aux=NULL;
  //verifico la cantidad
  if (dataCant<2) {
    printf("Tiene menos de dos elementos el vector\n");
    return -1;
  }
  //pido memoria para un vector adicional
  dataPtr_aux = (int*)realloc (dataPtr_aux,sizeof(*dataPtr_aux)*dataCant);
  if (dataPtr_aux == NULL) {
    printf("Error pidiendo memoria\n");
    return (-3);
  }
  //copio dataPtr
  for (int i = 0; i < dataCant; i++) {
    *(dataPtr_aux+i)=*(dataPtr+i);
  }
  //ordeno descendente creo
  for(int z = 1; z < dataCant; ++z) {
        for(int v = 0; v < (dataCant - z); v++) {
           if(dataPtr_aux[v] > dataPtr_aux[v+1]){
              aux = dataPtr_aux[v];
              dataPtr_aux[v] = dataPtr_aux[v + 1];
              dataPtr_aux[v + 1] = aux;
           }
        }
      }
  //verificacion visual
  /*
  for (int i = 0; i < dataCant; i++) {
    printf("%d\n",*(dataPtr_aux+i) );
  }
  for (int i = 0; i < dataCant; i++) {
    printf("%d\n",*(dataPtr+i) );
  }
  */
  for (int i = 0; i < dataCant; i++) {
    //son iguales estan ordenados accendente
    if (*(dataPtr_aux+i)-*(dataPtr+i)==0) {
      descendente++;
    }
    if (*(dataPtr_aux+(dataCant-1)-i)-*(dataPtr+i)==0) {
      ascendente++;
    }
  }
  //printf("ascendente=%d\n",ascendente );
  //printf("descendente=%d\n",descendente );
  free(dataPtr_aux);
  //entro todas las veces a ascendente
  if (ascendente==dataCant) {
    return 0;
  }
  //entro todas las veces a descendente
  if (descendente==dataCant) {
    return 1;
  }

  return-2;
}

int main() {
  //int vector[CANT]={0,1,2,3,4};
  //int vector[CANT]={4,3,2,1,0};
  int vector[CANT]={4,4,3,2,1};
  //int vector[CANT]={0,1,8,3,4};
  //int vector[1]={0};
  int a=verificarVect(vector,sizeof(vector)/sizeof(int));
  printf("a=%d\n",a );
  return 0;
}
