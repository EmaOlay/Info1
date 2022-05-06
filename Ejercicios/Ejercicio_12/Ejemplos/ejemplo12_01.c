#include <stdio.h>

#define  CANT ((int) 10)

int main() {
  int i;

  for (i = 0; i < CANT; i++) {
    printf("Hola Mundo, %d \r\n",i);
  }
  return 0;
}
