#include <stdio.h>

int main() {
  int a;
  //Ingreso de datos
  printf("Ingrese un numero:\r\n");
  scanf("%d",&a );
  //Verifico si vale cero
  if ((a<1)||(a>10)) {
    printf("El usuario ingreso un numero mayor a 10 o menor a 1\r\n");
  }
  return 0;
}
