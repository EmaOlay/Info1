#include <stdio.h>

float calculo(float opA, float opB, char op){
  float resultado=0;
  if (op =='+') {
    resultado = opA + opB;
  }
  if (op == '-') {
    resultado = opA - opB;
  }
  if (op == '*') {
    resultado = opA * opB;
  }
  if (op == '/') {
    resultado = opA / opB;
  }
  return resultado;
}

int main() {

  //declaro var
  float a,b,r;
  char c;
  //pido datos
  printf("Ingrese el primer numero\n");
  scanf("%f",&a );
  printf("Ingrese el segundo numero\n");
  scanf("%f",&b );
  while(getchar()!= '\n');
  //printf("Todavia tengo caracter del enter en buffer \n");por eso pongo el getchar
  printf("Ingrese la operacion que desea ingresar:\n");
  scanf("%c",&c );
  //calculo
  r=calculo(a,b,c);
  if (r==0) {
    printf("Error al calcular\n");
  } else {
    printf("El resultado de %g%c%g=%g.\n",a,c,b,r );
  }

  return 0;
}
