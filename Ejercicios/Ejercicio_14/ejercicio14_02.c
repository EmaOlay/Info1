#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define RANGO ((int) 100)



int main() {
  int historial[RANGO];
  //Me aseguro de vaciarlo
  for (int i = 0; i < RANGO; i++) {
    historial[i]=0;
    //printf("historial[%d]=%d\n",i,historial[i] );
  }
  int num_rand,num_ingre;
  srand(time(NULL));
  num_rand=rand()%100;
  printf("%d\n", num_rand);//lo muestro para probarlo...
  while (num_ingre!=num_rand) {
    printf("Ingrese un numero:\n");
    scanf("%d", &num_ingre);
    if ((num_ingre<0)||(num_ingre>99)) {
      printf("Numero fuera del rango...[0;99]\n");
    }else{
        if (historial[num_ingre]>0) {
          printf("Ya ingresaste ese numero\n");
        } else {
          historial[num_ingre]++;
        }
    }

  }
  printf("Le pegaste!\n");
  return 0;
}
