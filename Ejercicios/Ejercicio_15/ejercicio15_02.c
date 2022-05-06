#include <stdio.h>

void swap(int * a, int * b){
  int aux;
  aux=*a;
  *a=*b;
  *b=aux;
  return ;
}

int main() {
  int a,b;
  //Pido ints
  printf("Ingrese el primer numero\n");
  scanf("%d", &a);
  printf("Ingrese el segundo numero\n");
  scanf("%d", &b);

  //printf("Antes del swap a vale:%d\n", a);
  //printf("Antes del swap b vale:%d\n", b);
  swap(&a,&b);
  //printf("Despues del swap a vale:%d\n", a);
  //printf("Despues del swap b vale:%d\n", b);
  return 0;
}
