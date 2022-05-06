#include <stdio.h>
#include <math.h>

int main(void) {
  /* code */
float a, b, r;

//Ingreso de datos
printf("Ingrese un numero:\n" );
scanf("%f",&a);
printf("Ingrese un numero:\n" );
scanf("%f",&b);
//Imprimo una leyenda y el valor almacenado en la variable
r=a+b;
printf("La suma de %.3f + %.3f es igual a %.3f\r\n",a,b, r);
  return 0;
}
