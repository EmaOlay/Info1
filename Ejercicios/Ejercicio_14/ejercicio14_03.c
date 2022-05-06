#include <stdio.h>


int main() {
  float alturas[100];
  float num_ingre;
  int i=0,a,b,cant_tot,cant=0;
  //Mientras no ingresen alturas negativas
  //ni exceda 100 alturas sigo pidiendo

  while ((num_ingre>=0)&&(i<100)) {
    printf("Ingrese una altura\n");
    scanf("%f", &num_ingre);
    if (num_ingre>0) {
      alturas[i]=num_ingre;
      i++;
    }
  }
  cant_tot=i;//me guardo la cantidad de alturas totales
  //pido el rango de alturas
  printf("Ingrese la cota inf del rango\n");
  scanf("%d", &a);
  printf("Ingrese la cota sup del rango\n");
  scanf("%d", &b);
  //Checkeo que el rango sea valido
  if (a>=b) {
    printf("Rango invalido\n");
  }else{
    for (i = 0; i < cant_tot; i++) {
      if ((alturas[i]>=a)&&(alturas[i]<=b)) {
        cant++;
      }
    }
  }
  printf("La cantidad de alturas en el rango son:%d\n", cant);
  return 0;
}
