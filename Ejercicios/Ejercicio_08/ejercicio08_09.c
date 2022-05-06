#include <stdio.h>

int main() {
  /* code */
  float var;// declaracion de variable float
  //Imprimo en pantalla una leyenda
  printf("Ingrese un float:\r\n");
  //Espero a que el usuario ingrese un numero entero
  scanf("%f",&var );
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("El float redondeado es: %.02f\n",var);

  return 0;
}
