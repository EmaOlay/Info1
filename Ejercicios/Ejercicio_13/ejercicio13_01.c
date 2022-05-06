#include <stdio.h>
#include <math.h>

float areaCirculo(float radio){
  float resultado=-1;
  if (radio<0) {
    printf("El radio ingresado es negativo...\n");
  }else{
    resultado=M_PI * pow(radio,2);
  }

  return resultado;
}

int main() {
  float a;// declaro var
  //Pido dato
  printf("Ingrese un radio\n");
  scanf("%f", &a);
  if (areaCirculo(a)==-1) {
    printf("Error en el calculo del area\n");
  } else {
    printf("El area del circulo es: %f\n",areaCirculo(a) );
  }


  return 0;
}
