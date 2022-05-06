#include <stdio.h>

int main() {

  //declaro las variables probablemente se puede hacer con menos
  int a,b;

  //Recibo los numeros
  printf("Ingreso un numero\n");
  scanf("%d",&a );
  printf("Ingreso un numero\n");
  scanf("%d",&b );

  //Reviso quien es el limite superior e inferior
  //En base a eso elijo el for
  if (a<=b) {
    for (; a <= b; a++) {
      printf("%d\t", a);
    }
  }else{
    for (; a>=b; a--) {
      printf("%d\t", a);
    }
  }
  //Imprimi los numeros


  printf("\n");//Porque sino quedaba feo...
  return 0;
}
