#include "funciones.c"


#define  CANT 3



int main() {
  int resultado[CANT];
  for (int i = 0; i < CANT; i++) {
    resultado[i]=potencia(2+i, 2+i);
    printf("%d\n",resultado[i] );
  }


  return 0;
}
