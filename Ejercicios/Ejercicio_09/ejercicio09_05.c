#include <stdio.h>
#include <math.h>

int main(void) {

double a,r;

//Ingreso de datos
printf("Ingrese un angulo en grados, no en radianes:\n" );
scanf("%lf",&a);
a= a* M_PI /180;//cos recibe el angulo en rad asique aca lo transformo
//Imprimo una leyenda y el valor almacenado en la variable
r = cos(a);
printf("El coseno de %g es: %lf\r\n",a, r);
  return 0;
}
