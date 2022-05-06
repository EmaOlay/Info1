#include <stdio.h>

int main() {

  char varChar = 'c';//declaracion de variable char
  int varInt=0x55AA;// declaracion de variable entera
  int varInt2 =017;// declaracion de variable entera
  float varFloat=1.27;//declaracion de variable float
  double varDouble=2.7172;//declaracion de variable double

  //Imprimo una leyenda y el valor almacenado en la variable
  printf("char: varChar %c\n",varChar);
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("int: varInt %#02x\n",varInt);
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("int: varInt %03o\n",varInt2);//Esta cosa esta en octal si le metes %d te tira 15 cualquera
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("float: varFloat %.2f\n",varFloat);
  //Imprimo una leyenda y el valor almacenado en la variable
  printf("double: varDouble %.4f\n",varDouble);
  return 0;
}
