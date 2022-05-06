#include <stdio.h>
#include <math.h>

int main(void) {

double a,r;

//Ingreso de datos
printf("Ingrese un numero:\n" );
scanf("%lf",&a);

//Imprimo una leyenda y el valor almacenado en la variable
r = log2(a);
printf("El logaritmo en base 2 de %g es %g\r\n",a, r);

  return 0;
}
