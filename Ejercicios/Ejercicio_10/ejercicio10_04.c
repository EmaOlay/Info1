#include <stdio.h>

int main() {
  //declaro var
  float a,b;
  char c;
  //Ingreso datos
  printf("Ingrese el primer numero.\n");
  scanf("%f",&a);
  printf("Ingrese el segundo numero.\n");
  scanf("%f",&b);
  printf("Ingrese la operacion.\n");
  scanf("%*c%c",&c);//magia negra de Jero
  //Uso el switch
  switch (c) {
    case '+':
    printf("La operacion %g %c %g =%g\n",a,c,b,a+b );
    break;
    case '-':
    printf("La operacion %g %c %g =%g\n",a,c,b,a-b );
    break;
    case '*':
    printf("La operacion %g %c %g =%g\n",a,c,b,a*b );
    break;
    case '/':
    printf("La operacion %g %c %g =%g\n",a,c,b,a/b );
    break;
    default:
    printf("Operacion no valida\n");
    break;
  }

  return 0;
}
