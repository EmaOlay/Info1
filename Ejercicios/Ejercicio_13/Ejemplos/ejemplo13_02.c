#include <stdio.h>



void imprimir(int count){
  int i;
  for ( i = 0; i < count; i++) {
    printf("Hola Mundo\n");
  }

}
int main() {
  int c;
  printf("Ingrese la cantidad de veces a imprimir\n");
  scanf("%d",&c );
  imprimir(c);
  return 0;
}
