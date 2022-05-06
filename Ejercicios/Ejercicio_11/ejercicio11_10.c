
#include <stdio.h>
#include <math.h>

int main() {

  //declaro variables
  int numero,i=1;
  //Pido un numero
  printf("Ingrese un numero\n");
  scanf("%d",&numero);
  while ((sqrt(pow(numero,2)))>1) {
    numero=numero/10;
    if (numero==0) {
      printf("El numero se dividio %d veces y ahora vale:%d\n",i, numero);
    }else{
      i++;
    }


  }
  printf("El numero tiene %d cifras.\n",i );
  return 0;
}
