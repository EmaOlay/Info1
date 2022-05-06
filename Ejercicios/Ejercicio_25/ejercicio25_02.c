#include "funciones.c"

#define  CANT 10

int main() {
  int resultado[CANT];
  //{1,1,2,3,5,8,13,21,34,55,89,144...}
  for (int i = 0; i < CANT; i++) {
    resultado[i]=fibonacci(i);
    printf("F_%d=%d\n",i,resultado[i] );
  }

  return 0;
}
