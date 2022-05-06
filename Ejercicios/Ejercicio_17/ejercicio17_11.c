#include <stdio.h>
#include <stdlib.h>


char* imprimirBinario(int n){
  int i=0;
  char *p;
  //El max int es 2147483647 mas de 31 no necesito
  p = (char*)malloc (sizeof (*p) * 31);
  if (p==NULL) {
    printf("Error al pedir memoria\n");
    return NULL;
  }
  while (n>0) {
    //*(p+30-i)=dividendo_aux%2; HAcer algo con esto?
    if (n%2 == 1) {
      //printf("1");
      *(p+30-i)='1';
    }else{
      //printf("0");
      *(p+30-i)='0';
    }
    n/=2;
    i++;
  }
  for (int j = 0; j <31 - i; j++) {
    *(p+j)=' ';
  }

  return p;
}

int main() {
  int a;
  char * puntero;

  printf("Ingrese un numero\n");
  scanf("%d", &a);
  printf("El numero ingresado es: %d\n",a);
  puntero=imprimirBinario(a);
  printf("El numero binario es:%s\n", puntero);
  free(puntero);
  return 0;
}
