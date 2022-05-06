#include <stdio.h>

#define  CANT ((int) 25)

int main() {
  char alfabeto[CANT];
  for (int i = 0; i < CANT; i++) {
    alfabeto[i]=97+i;
  }
  for (int i = 0; i < CANT; i++) {
    printf("Las letras de alfabeto son: %c\n", alfabeto[i]);
  }
  return 0;
}
