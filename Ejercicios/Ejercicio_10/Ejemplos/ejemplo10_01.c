#include <stdio.h>

int main() {
  int a;
  //Ingreso de datos
  printf("Ingrese un numero:\r\n");
  scanf("%d",&a );
  //Verifico si vale cero
  if (a==0) {
    printf("El usuario ingreso cero\r\n");
  }
  return 0;
}
