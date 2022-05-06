#include <stdio.h>

int main() {
  //declaro variables
  int a,acumulacion=0;

  while (acumulacion<=100) {
    printf("Ingrese una variable a acumular: \n");
    scanf("%d",&a);
    acumulacion+=a;
  }
  printf("La acumulacion supero 100.\nEl ultimo valor acumulado fue:%d\r\n",acumulacion-a );
  //hago el acumulacion-a porque entro al while y se hizo la acumulacion pero no me pideron
  //Que muestre eso. asique meehhh
  return 0;
}
