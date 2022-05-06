#include <stdio.h>
#define CANT ((int) 3)
int orden (int *dataPtr, int dataCant){
  int Asce=0,Desce=0;
  for (int i = 0; i < dataCant-1; i++) {//el menos 1 es porque no necesito que lo haga tantas veces
    if (*(dataPtr+i)>=*(dataPtr+1+i)) {
      Asce++;
    }
    if (*(dataPtr+i)<=*(dataPtr+1+i)) {
      Desce++;
    }
  }
  if (Asce>0 && Desce>0) {
    return 0;
  }
  if (Asce>0 && Desce==0) {
    return 1;
  }
  if (Desce>0 && Asce==0) {
    return -1;
  }
  printf("Si llego hasta aca la cagamo' pero para solucionar el warning\n");
  return -2;
}

int main() {
  int vector[CANT];
  int estado;
  for (int i = 0; i < CANT; i++) {
    printf("Ingrese un numero.\n");
    scanf("%d", &vector[i]);
  }
  estado=orden(&vector[0],CANT);
  switch (estado) {
    case 0:
    printf("Orden mixto\n");
    break;
    case 1:
    printf("Orden Ascendente\n");
    break;
    case -1:
    printf("Orden Descendiente\n");
    break;
  }
  return 0;
}
