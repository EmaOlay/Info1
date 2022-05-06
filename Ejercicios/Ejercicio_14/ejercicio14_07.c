#include <stdio.h>
#include <stdlib.h>

int main() {
  int i=0;
  int flag_no_igual=0;
  char palabra1[50];//asumo que la palabra no excede las 50 letras
  char palabra2[50];
  printf("Ingrese la primer palabra\n");
  scanf("%s", &palabra1[0]);
  printf("Ingrese la segunda palabra\n");
  scanf("%s", &palabra2[0]);
  //busco el \0 porque es lo que pone el scanf al final
  while ((palabra1[i]!='\0')||(palabra2[i]!='\0')) {
    if (palabra1[i]<palabra2[i]) {
      printf("La palabra %s, viene antes en el diccionario que %s\n",palabra1,palabra2 );
      flag_no_igual=1;
      exit(0);
    }else{ if (palabra1[i]>palabra2[i]) {
      printf("La palabra %s, viene despues en el diccionario que %s\n",palabra1,palabra2 );
      flag_no_igual=1;
      exit(0);
    }

  }
  i++;
}
  if (flag_no_igual==0) {
    printf("La palabra %s, es igual a la palabra %s\n",palabra1,palabra2 );
  }
    //Tecnicamente no verifico que sea una palabra pero buee
    i++;

  return 0;
}
