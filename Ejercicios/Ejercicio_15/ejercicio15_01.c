#include <stdio.h>

#define  CANT ((int) 4)

float promedio(float * dataPtr, int dataCant){
  float promedio=0;
  for (int i = 0; i < dataCant; i++) {
    promedio+= *(dataPtr +i);

  }
  return (promedio/dataCant);
}

int main() {
  float vector[CANT];
  float Promedio;
  //Pido floats
  for (int i = 0; i < CANT; i++) {
    printf("Ingrese un float\n");
    scanf("%f", &vector[i]);
  }
  Promedio=promedio(vector, CANT);
  printf("%g\n", Promedio);
  return 0;
}
