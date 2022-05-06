#include <stdio.h>

int main() {
  int a,b;
  //Ingreso de datos
  printf("Ingrese un numero\n");
  scanf("%d",&a );
  //calculo el resto
  b=a%2;
  //Muestro resultados
  if (b==1) {
    printf("El numero es impar\n");
  } else {
    printf("El numero es par\n");
  }

  return 0;
}
