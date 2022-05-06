#include <stdio.h>

int main() {
  /* code */
  char var;// declaracion de variable char
  //Imprimo en pantalla una leyenda
  printf("Ingrese una letra:\r\n");
  //Espero a que el usuario ingrese un numero entero
  scanf("%c",&var );
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("La letra ingresada es: %c\n",var);
  return 0;
}
