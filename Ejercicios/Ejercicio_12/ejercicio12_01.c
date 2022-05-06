#include <stdio.h>


#define  UMBRAL ((int) 100)

int main() {
  //declaro var
  int a;
  //pido ingreso de dato
  printf("Ingrese un numero\n");
  scanf("%d",&a );
  //Evaluo el dato e imprimo
  if (a>100) {
  printf("El numero ingresado es mayor a 100\r\n");
}else{
  printf("El numero ingresado no es mayor a 100\r\n");
}
  return 0;
}
