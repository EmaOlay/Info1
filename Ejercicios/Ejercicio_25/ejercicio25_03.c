#include "funciones.c"
//gcc -Wall ejercicio25_03.c -o ejercicio25_03.out -lm
#define  CANT 15

int main() {
  int dato=0;
  int *p;
  int bits=0;

  for (int i = 1; i < 15; i++) {
    dato=i;
    //calculo los bits necesarios
    bits=floorf(log2(dato))+1;
    //printf("%d\n",bits );
    //pido memoria para esa cantidad de bits

    p=(int*)malloc(sizeof(int)*bits);
    if (bits!=0) {
      pasaje(dato,p);
      printf("Dato=%d\t",dato );
      //imprimo los bits
        for (int i = bits-1; i >=0; i--) {
          printf("%d",*(p+i));
        }
      printf("\n");
    }
    free(p);
  }
  return 0;
}
