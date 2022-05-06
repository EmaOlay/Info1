#include "funciones.c"

int main() {
  int bit;

  bit=leerBit(2, 1);
  printf("%d\n",bit );

  bit=leerBit(3, 1);
  printf("%d\n",bit );

  bit=leerBit(3, 0);
  printf("%d\n",bit );
  return 0;
}
