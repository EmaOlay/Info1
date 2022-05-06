#include <stdio.h>

int main() {
  /* code */
  float var;// declaracion de variable float
  //Imprimo en pantalla una leyenda
  printf("Ingrese un float:\r\n");
  //Espero a que el usuario ingrese un numero entero
  scanf("%f",&var );
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("La letra ingresada es: %f\n",var);
  return 0;
}
