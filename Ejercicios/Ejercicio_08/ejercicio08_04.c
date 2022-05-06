#include <stdio.h>

int main() {
  /* code */
  int var;// declaracion de variable entera
  //Imprimo en pantalla una leyenda
  printf("Ingrese un numero:\r\n");
  //Espero a que el usuario ingrese un numero entero
  scanf("%d",&var );
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("El numero ingresado es: %d\n",var);
  return 0;
}
