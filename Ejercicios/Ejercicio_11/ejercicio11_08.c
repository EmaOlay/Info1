#include <stdio.h>

int main() {
  //declaro variable
  int acumul=0,i=0,b;
  float promedio;
  do {
    //Pido notas
    printf("Ingrese una nota:\n");
    scanf("%d",&b);
    if ((b>0)&&(b<11)) {
      acumul+=b;
      i++;
    }else{
      printf("Ingrese una nota valida...\n");
    }
    if ((b==-1)&&(i<=3)) {
      printf("Capaz queres salir pero...\nQue la cantidad de notas validas ingresadas sea mayor que 3.\n");
      b=0;
    }

  } while((b!=-1));


    promedio=(acumul)/(i);
    printf("El promedio es: %.02f\n",promedio );

  return 0;
}
