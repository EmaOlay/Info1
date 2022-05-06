#include <stdio.h>

int main() {
  int a, suma=0;
  while (suma<=100) {
    printf("Ingrese un numero:\r\n");
    scanf("%d",&a );
    suma+= a;
  }
  printf("La suma es %d\r\n", suma);
  return 0;
}
