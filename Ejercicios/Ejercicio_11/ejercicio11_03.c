#include <stdio.h>

int main() {

  //declaro variables
  int i,a, promedio=0;

  for ( i = 0; i < 10; i++) {
    printf("Ingrese un numero para promediar:\n");
    scanf("%d",&a );
    promedio=promedio+a;
  }
  printf("El promedio es: %d\r\n",promedio/10 );
  return 0;
}
