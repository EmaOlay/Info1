#include <stdio.h>

int main() {
  char a;
  //Ingreso de datos
  printf("Ingrese un caracter:\r\n");
  scanf("%c",&a );
  //Verifico si vale cero
  if ((a>='A')&&(a<='Z')) {
    printf("El caracter ingresado es una letra mayuscula\r\n");
  }
  return 0;
}
