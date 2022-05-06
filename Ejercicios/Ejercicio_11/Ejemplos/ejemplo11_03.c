#include <stdio.h>

int main() {
  int a;
  do {
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
  } while(a<10);
  printf("El numero ingresado fue mayor que 9\r\n");
  return 0;
}
