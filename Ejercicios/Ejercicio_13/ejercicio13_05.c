#include <stdio.h>
#include <math.h>

float Hipotenusa(float opA, float opB){
  float resultado=-1;
  if ((opA<=0)||(opB<=0)) {
    printf("Alguno de los catetos no es valido\n");
  } else {
    resultado=sqrt(pow(opA,2)+pow(opB,2));
  }
  return resultado;
}

int main() {

  //declaro var
  float a,b,r;

  //pido datos
  printf("Ingrese el primer cateto\n");
  scanf("%f",&a );
  printf("Ingrese el segundo cateto\n");
  scanf("%f",&b );

  //calculo
  r=Hipotenusa(a,b);
  if (r==-1) {
    printf("Error al calcular la hipotenusa\n");
  } else {
    printf("La hipotenusa del triangulo propuesto es: %g.\n",r );
  }

  return 0;
}
