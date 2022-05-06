#include <stdio.h>
#include <math.h>

int main(void) {

int a, b, cociente, resto;

//Ingreso de datos
printf("Ingrese un numero:\n" );
scanf("%d",&a);
printf("Ingrese un numero:\n" );
scanf("%d",&b);
//Imprimo una leyenda y el valor almacenado en la variable
cociente=a/b;
resto=a%b;

printf("El cociente es: %d\n",cociente );
printf("El resto es: %d\r\n", resto);
  return 0;
}
