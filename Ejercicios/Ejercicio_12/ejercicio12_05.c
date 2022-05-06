#include <stdio.h>

int main() {
  int i=0,array,pares=0, impares=0;
  while (i<CANT) {
    printf("Ingrese un numero entero positivo\n");
    scanf("%d",&(array) );
    if (array>0) {
      if (array%2 == 0) {
        pares++;
      }else{
        impares++;
      }
      i++;
    }
  }
  printf("La cantidad de pares ingresados fue:%d y los impares:%d\n",pares, impares );
  return 0;
}
