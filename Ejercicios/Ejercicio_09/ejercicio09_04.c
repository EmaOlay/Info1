#include <stdio.h>
#include <math.h>

int main(void) {

double a,r;

//Ingreso de datos
printf("Ingrese un numero:\n" );
scanf("%lf",&a);

//Imprimo una leyenda y el valor almacenado en la variable
r = sqrt(a);
printf("El resultado es: %.4f\r\n", r);

//Si el numero ingresado es negativo devuelve -nan  la funcion
  return 0;
}
