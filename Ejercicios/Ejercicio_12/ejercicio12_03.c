#include <stdio.h>

int main() {

    //Teorema de Wilson
    //Un numero n es primo si y solo si(n-1)!+1 es multiplo de n
    //Reutilizo el factorial
    int i, a,aux,factorial=1,resto;//factorial lo inicio en 1 ya que para la multiplicacion no pincha ni corta

    //pido ingresen dato
    printf("Ingrese un numero\n");
    scanf("%d",&a );
    aux=a-1;
    if (aux<0) {
      printf("No puedo calcular el factorial de un numero negativo.\n");

    }else{
      for (i = 0; i < aux; ++i) {
  //Como i arranca en 0 le sumo 1 para que no multiplique por 0
        factorial=factorial*(i+1);
      }
      printf("El factorial de %d, es:%d.\n",aux,factorial );
    }
  printf("Nuestro factorial anterior:%d +1=%d\n",factorial,factorial+1 );
  resto= (factorial+1)%a;
  if (resto ==0) {
    printf("La division de %d,es exacta con %d por lo tanto %d es primo\n",factorial+1,a,a );
  }else{
    printf("La division de %d, NO es exacta con %d por lo tanto %d NO es primo\n",factorial+1,a,a );
  }
  return 0;
}
