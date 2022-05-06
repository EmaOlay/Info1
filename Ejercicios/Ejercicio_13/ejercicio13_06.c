#include <stdio.h>

int factorial(int a){
int i,factorial=1;//factorial lo inicio en 1 ya que para la multiplicacion no pincha ni corta

if (a<0) {
  printf("No puedo calcular el factorial de un numero negativo.\n");
  factorial=0;
}else{
  for (i = 0; i < a; ++i) {
//Como i arranca en 0 le sumo 1 para que no multiplique por 0
    factorial=factorial*(i+1);
  }
  printf("El factorial de %d, es:%d.\n",a,factorial );
}
return factorial;
}

int main() {
  int a;
  printf("Ingrese un numero\n");
  scanf("%d", &a);
  factorial(a);
  //printf("La funcion tambien devuelve el resultado:%d\n", factorial(a));
  return 0;
}
