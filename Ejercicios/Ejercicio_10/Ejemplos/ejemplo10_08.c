#include <stdio.h>

int main() {
  char a;
  //Ingreso de datos
  printf("Ingrese un caracter:\r\n");
  scanf("%c",&a );
  //Verifico si es vocal
  switch(a){
    case 'a':
    printf("Es vocal\n");
    break;
    case 'e':
    printf("Es vocal\n");
    break;
    case 'i':
    printf("Es vocal\n");
    break;
    case 'o':
    printf("Es vocal\n");
    break;
    case 'u':
    printf("Es vocal\n");
    break;
    default:
    printf("No es vocal\n");
    break;
  }
  return 0;
}
