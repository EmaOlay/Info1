#include <stdio.h>

int main() {
  //Ingreso de datos
  char a;
  int estado;
  printf("Ingrse un dato\n");
  scanf("%c",&a );
  printf("%c\n",a);
  if ((a>=97)&&(a<=122)) {
    estado=0;
  }
  if ((a>=65)&&(a<=90)) {
    estado=1;
  }
  if((a>='0')&&(a<='9')){
    estado=2;
  }
  switch (estado) {
    case 0:
    printf("Es una letra minuscula\n");
    break;
    case 1:
    printf("Es una letra mayuscula\n");
    break;
    case 2:
    printf("Es un numero\n");
    break;
    default:
    printf("Es otro caracter\n");
    break;
  }
  return 0;
  }
