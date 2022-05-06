#include <stdio.h>

int main() {
  int a;
  //Ingreso de datos
  printf("Ingrese un caracter:\r\n");
  scanf("%d",&a );
  //Verifico si es vocal
  switch(a){
    case 0:
    printf("cero\n");
    break;
    case 1:
    printf("uno\n");
    break;
    case 2:
    printf("dos\n");
    break;
    case 3:
    printf("tres\n");
    break;
    case 4:
    printf("cuatro\n");
    break;
    case 5:
    printf("cinco\n");
    break;
    case 6:
    printf("seis\n");
    break;
    case 7:
    printf("siete\n");
    break;
    case 8:
    printf("ocho\n");
    break;
    case 9:
    printf("nueve\n");
    break;
    default:
    printf("Lo ingresado no es valido\n");
    break;
  }
  return 0;
}
