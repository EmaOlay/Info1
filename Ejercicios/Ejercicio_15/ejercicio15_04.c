#include <stdio.h>
#define CANT ((int) 3)
int * myMax (int *dataPtr, int dataCant){
  int max_aux, pos;
  max_aux= *(dataPtr);
  pos=0;
  for (int i = 0; i < dataCant-1; i++) {
    if (max_aux<= *(dataPtr+i+1)) {
      //el segundo es mas grande lo guardo
      max_aux=*(dataPtr+i+1);
      pos=i+1;
    }
  }
  return (dataPtr + pos);
}

int main() {
  int vector[CANT];
  int * ptr;
  for (int i = 0; i < CANT; i++) {
    printf("Ingrese un numero.\n");
    scanf("%d", &vector[i]);
  }
  ptr= myMax(&vector[0], CANT);
  printf("El maximo vale: %d\n", *ptr);
  return 0;
}
