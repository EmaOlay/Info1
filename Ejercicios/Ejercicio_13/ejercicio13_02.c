#include <stdio.h>
#include <math.h>

float perimetroCirculo(float radio){
  float resultado=-1;
  if (radio<0) {
    printf("El radio ingresado es negativo...\n");
  }else{
    resultado=M_PI * 2 * radio;
  }

  return resultado;
}

int main() {
  float a;// declaro var
  //Pido dato
  printf("Ingrese un radio\n");
  scanf("%f", &a);
  if (perimetroCirculo(a)==-1) {
    printf("Error en el calculo del perimetro\n");
  } else {
    printf("El perimetro del circulo es: %f\n",perimetroCirculo(a) );
  }


  return 0;
}
