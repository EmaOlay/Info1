#include <stdio.h>

int main() {
  int i, a,factorial=1;//factorial lo inicio en 1 ya que para la multiplicacion no pincha ni corta

  //pido ingresen dato
  printf("Ingrese un numero\n");
  scanf("%d",&a );
  if (a<0) {
    printf("No puedo calcular el factorial de un numero negativo.\n");

  }else{
    for (i = 0; i < a; ++i) {
//Como i arranca en 0 le sumo 1 para que no multiplique por 0
      factorial=factorial*(i+1);
    }
    printf("El factorial de %d, es:%d.\n",a,factorial );
  }

  return 0;
}
// Parace que el limite de esto es 13 ya que 17 hace overflow y de 13 en adelante tira basura.
