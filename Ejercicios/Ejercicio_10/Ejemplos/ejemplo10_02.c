#include <stdio.h>

int main() {
  int a;
  //Ingreso de datos
  printf("Ingrese un numero:\r\n");
  scanf("%d",&a );
  //Verifico si es mayor o igual a 6
  if (a>=6) {
    printf("El numero ingresado es mayor o igual a 6\r\n");
  }else{
    printf("El numero ingresado es menor a 6\r\n");
  }
  return 0;
}
