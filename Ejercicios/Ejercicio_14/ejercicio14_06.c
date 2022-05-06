#include <stdio.h>

int main() {
  int i=0;
  char palabra[50];//asumo que la palabra no excede las 50 letras
  printf("Ingrese una palabra\n");
  scanf("%s", &palabra[0]);
  //busco el \0 porque es lo que pone el scanf al final
  while (palabra[i]!='\0') {

    //Tecnicamente no verifico que sea una palabra pero buee
    i++;
  }

  printf("La palabra tiene %d caracteres.\n", i);


  return 0;
}
