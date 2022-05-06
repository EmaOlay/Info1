#include <stdio.h>
#include <math.h>

int main(void) {

double a,b,r;

//Ingreso de datos
printf("Ingrese primer cateto:\n" );
scanf("%lf",&a);
printf("Ingrese segundo cateto:\n" );
scanf("%lf",&b);
//Imprimo una leyenda y el valor almacenado en la variable
r = pow(a,2)+pow(a,2);
printf("El hipotenusa es: %.4f\r\n", sqrt(r));

//Si el numero ingresado es negativo devuelve -nan  la funcion
  return 0;
}
