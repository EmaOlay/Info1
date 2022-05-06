#include <stdio.h>

int main() {
  int i=0,j=0;
  char palabra[50];//asumo que la palabra no excede las 50 letras
  char caracter;
  printf("Ingrese una palabra\n");
  scanf("%s", &palabra[0]);
  printf("Ingrese un caracter\n");
  scanf("%c", &caracter);//se chupa el \n del scanf anterior...
  scanf("%c", &caracter);
  //busco el \0 porque es lo que pone el scanf al final
  while (palabra[i]!='\0') {
    if (palabra[i]==caracter) {
      palabra[i]='*';
      j++;
    }

    i++;
  }

  printf("La palabra tiene %d caracteres seleccionados.\n", j);
  printf("Y queda de la siguiente forma: %s\n", palabra);


  return 0;
}
