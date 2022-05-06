#include <stdio.h>
#define CANT ((int) 10)

int main() {
  int array[CANT];
  int vec_PosyCero[CANT],vec_Negativos[CANT],vec_Pares[CANT],vec_Impares[CANT];
  //los inicializo por las dudas
  for (int i = 0; i < CANT; i++) {
    vec_PosyCero[i]=0;
    vec_Negativos[i]=0;
    vec_Pares[i]=0;
    vec_Impares[i]=0;
  }
  int PosyCero=0, Negativos=0,Pares=0,Impares=0;
  for (int i = 0; i < 10; i++) {
    printf("Ingrese un numero\n");
    scanf("%d",(array +i) );
    if (array[i]>=0) {
      vec_PosyCero[PosyCero]=array[i];
      PosyCero++;
    }
    if (array[i]<0) {
      vec_Negativos[Negativos]=array[i];
      Negativos++;
    }
    if ((array[i]%2)==0) {
      vec_Pares[Pares]=array[i];
      Pares++;
    }
    if (((array[i]%2)==-1)||((array[i]%2)==1)) {
      vec_Impares[Impares]=array[i];
      Impares++;
    }
  }
  printf("Los Positivos y ceros son:%d\n", PosyCero);
  for (int i = 0; i < PosyCero; i++) {
    printf("%d\t",vec_PosyCero[i] );
  }
  printf("\n");
  printf("Los Negativos son: %d\n", Negativos);
  for (int i = 0; i < Negativos; i++) {
    printf("%d\t",vec_Negativos[i] );
  }
  printf("\n");
  printf("Los pares son: %d\n", Pares);
  for (int i = 0; i < Pares; i++) {
    printf("%d\t",vec_Pares[i] );
  }
  printf("\n");
  printf("Los impares son: %d\n", Impares);
  for (int i = 0; i < Impares; i++) {
    printf("%d\t",vec_Impares[i] );
  }
  printf("\n");
  return 0;
}
