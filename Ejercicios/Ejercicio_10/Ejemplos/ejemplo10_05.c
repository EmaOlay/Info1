#include <stdio.h>

int main() {
  int a;
  //Ingreso de datos
  printf("Ingrese un numero:\r\n");
  scanf("%d",&a );
  //Verifico si vale cero
  if ((a>=1)&&(a<=10)) {
    printf("El usuario ingreso un numero entre 1 y 10\r\n");
  }
  return 0;
}
