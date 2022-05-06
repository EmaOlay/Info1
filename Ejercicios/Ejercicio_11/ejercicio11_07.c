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

    //printf("La variable acumul vale: %d\nY la variable i: %d\n",acumul,i );
    //Esta linea es el porque esta tan parchado el promedio jajajaja
  } while((b!=-1));


    promedio=(acumul)/(i);
    printf("El promedio es: %.02f\n",promedio );

  return 0;
}
