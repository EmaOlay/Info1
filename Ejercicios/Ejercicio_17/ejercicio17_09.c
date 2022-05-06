#include <stdio.h>

int luhnAlg(char *tarjeta){
  int i=0;
  int aux_par=0,aux_impar=0,S=0;
  while (*(tarjeta+i)!='\0') {
    if ((i%2)==0) {//pos par
      if (*(tarjeta+i)*2 >=10) {
        aux_par+=(*(tarjeta+i)*2);
      }
    }
    if ((i%2)==1) {//pos impar
      aux_impar+=(*(tarjeta+i)*1);
    }
    i++;
  }
  S=aux_par+aux_impar;
  if (i!=16) {
    return (-1);
  }
  if (S%10==0) {
    return 0;
  }
  return (-2);
}

int main() {
  int a;
  char num_tar[20];//si fuerzo 16 felxibiliza la condcion i!=16
  printf("Ingrese un numero de tarjerta\n");
  scanf("%s", num_tar);
  a=luhnAlg(num_tar);
  if (a==0) {
    printf("La tarjeta es valida\n");
  }
  if (a==-1) {
    printf("La tarjeta no tiene 16 caracteres\n");
  }
  if (a==-2) {
    printf("La tarjeta no es valida\n");
  }
  return 0;
}
