#include <stdio.h>
int main() {
  int a,b;

  //Ingreso de datos
  printf("Ingrese un numero:\n");
  scanf("%d",&a);
  printf("Ingrese un numero:\n");
  scanf("%d",&b);

  //Compara los numeros

  if(a==b){
    printf("Son iguales\n");
  }else{
    if (a>b) {
      printf("El primer numero es mayor que el segundo\n");
    } else {
      printf("El primero numero es menor que el segundo\n");
    }
  }
  return 0;
}
