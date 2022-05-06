#include <stdio.h>

int eliminarCaracter(char *dataPtr, char c){
    int i=0,j=0,x;

    //busco el \0 porque es lo que pone el scanf al final
    while (*(dataPtr+i)!='\0') {
      if (*(dataPtr+i)==c) {
        x=i;
        while (*(dataPtr+x)!='\0') {
          *(dataPtr+x)=*(dataPtr+x+1);
          x++;
        }

        j++;
      }
      i++;
    }
return j;
}

int main() {
  int j;
  char palabra[50];//asumo que la palabra no excede las 50 letras
  char caracter;
  printf("Ingrese una palabra\n");
  scanf("%s", &palabra[0]);
  printf("Ingrese un caracter\n");
  scanf("%c", &caracter);//se chupa el \n del scanf anterior...
  scanf("%c", &caracter);
  j=eliminarCaracter(palabra,caracter);
  printf("La palabra tiene %d caracteres seleccionados.\n", j);
  printf("Y queda de la siguiente forma: %s\n", palabra);
  return 0;
}
