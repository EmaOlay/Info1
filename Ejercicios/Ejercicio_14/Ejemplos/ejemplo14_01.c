#include <stdio.h>


#define  CANT ((int) 10)

int main(int argc, char const *argv[]) {
  int v[CANT];
  int i;
  //Inicializo el vector
  for ( i = 0; i < CANT; i++) {
    v[i] = i;
  }
  //Imprimo en orden ascendente
  for ( i = 0; i < CANT; i++) {
    printf("%d\n",v[i] );
  }
  for ( i = CANT - 1; i >=0; i--) {
    printf("%d\n",v[i] );
  }
  return 0;
}
