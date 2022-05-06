#include "funciones.c"

int main() {
  int bit;

  bit=negarBit((unsigned int)2, 1);
  printf("%d\n",bit );

  bit=negarBit((unsigned int)3, 1);
  printf("%d\n",bit );

  bit=negarBit((unsigned int)3, 30);
  printf("%x\n",bit );
  return 0;
}
