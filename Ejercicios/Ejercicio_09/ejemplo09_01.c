#include <stdio.h>
#include <math.h>

int main(void) {
  /* code */
double a, b, r;

//Ingreso de datos
printf("Ingrese un numero:\n" );
scanf("%lf",&a);
printf("Ingrese un numero:\n" );
scanf("%lf",&b);
//Imprimo una leyenda y el valor almacenado en la variable
r=pow(a,b);
printf("El resultado es: %f\r\n", r);
  return 0;
}
