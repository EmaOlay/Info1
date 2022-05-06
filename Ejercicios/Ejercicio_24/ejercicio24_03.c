#include "funciones.c"

#define  count 3

int main() {
  int bit;
  int palabra;

  bit=escribirBit(2, 1,0);
  printf("%d\n",bit );

  bit=escribirNibble(0x04, 1,0);
  printf("%d\n",bit );
  
  bit=escribirNibble(0x04, 0,0);
  printf("%d\n",bit );

  bit=escribirBit(0x04, 0,0);
  printf("%d\n",bit );
  return 0;
}
