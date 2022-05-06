#include <stdio.h>

int main() {
  /* code */
  int var;// declaracion de variable entera
  //Imprimo en pantalla una leyenda
  printf("Ingrese un numero en hexa:\r\n");
  //Espero a que el usuario ingrese un numero entero
  scanf("%x",&var );
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("El numero ingresado es: %x(Hexadecimal);%o (octal);%d (Decimal)\r\n",var,var,var);

  return 0;
}
