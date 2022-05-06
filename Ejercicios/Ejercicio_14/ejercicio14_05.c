#include <stdio.h>

int main() {
  int i=0;
  char palabra[50];//asumo que la palabra no excede las 50 letras
  printf("Ingrese una palabra\n");
  scanf("%s", &palabra[0]);
  //busco el \0 porque es lo que pone el scanf al final
  while (palabra[i]!='\0') {

    if ((palabra[i]>='a')&&(palabra[i]<='z')) {
      palabra[i]-=('a'-'A');
    }
    i++;
  }

  printf("La palabra en mayus es: %s\n", palabra);


  return 0;
}
