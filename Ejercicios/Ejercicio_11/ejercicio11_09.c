#include <stdio.h>

int main() {
  int num_sec=-1,num_rand,i=0;

  //Pido un numero secreto hasta que me lo den!!!!!!!!
  while ((num_sec<0)||(num_sec>9)) {
    printf("Ingrese un numero secreto entre 0 y 9:\n");
    scanf("%d",&num_sec );
  }

  //Mis dos condiciones de salida son o pegarle o errar 3 veces
  while ((num_sec!=num_rand)&&(i<3)) {
    printf("Trata de adivinar el numero:\n");
    scanf("%d",&num_rand );
    if ((num_rand<0)||(num_rand>9)) {
      printf("Ingrese un numero valido.\n");
      num_rand=-1;
    }else{
      i++;
    }

  }
  if (num_sec==num_rand) {
    printf("GANASTE\n");
  }
  if (i>=3) {
    printf("NO GANASTE, Intentalo otra vez\nTus intentos:%d\n",i);
  }
  return 0;
}
