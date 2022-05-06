#include <stdio.h>
#include <stdlib.h>
int main() {
  //declaro var
  float a,b;
  int estado;
  //Ingreso datos
  printf("Ingrese el primer parcial.\n");
  scanf("%f",&a);
  printf("Ingrese el segundo parcial.\n");
  scanf("%f",&b);

  //verifico las notas
  if((a<1)||(a>10)){
    printf("La nota del primer parcial no es valida.\n");
    exit(0);
  }
  if((b<1)||(b>10)){
    printf("La nota del segundo parcial no es valida.\n");
    exit(0);
  }

  //Uso el switch
  estado=(a+b)/2;

  switch (estado) {
    case 0:
    printf("Debe recuperar algun parcial.\n");
    break;
    case 1:
    printf("Debe recuperar algun parcial.\n");
    break;
    case 2:
    printf("Debe recuperar algun parcial.\n");
    break;
    case 3:
    printf("Debe recuperar algun parcial.\n");
    break;
    case 4:
    printf("Debe recuperar algun parcial.\n");
    break;
    case 5:
    printf("Debe recuperar algun parcial.\n");
    break;
    case 6:
    if ((a>=6)&&(b>=6)) {
      printf("Firmo la materia.\n");
    }else{
      printf("Debe recuperar algun parcial.\n");
    }
    break;
    case 7:
    if ((a>=6)&&(b>=6)) {
      printf("Firmo la materia.\n");
    }else{
      printf("Debe recuperar algun parcial.\n");
    }
    break;
    case 8:
    if ((a>=6)&&(b>=6)) {
      printf("Promociono.\n");
    }else{
      printf("Debe recuperar algun parcial.\n");
    }
    break;
    case 9:
    if ((a>=6)&&(b>=6)) {
      printf("Promociono.\n");
    }else{
      printf("Debe recuperar algun parcial.\n");
    }
    break;
    case 10:
    if ((a>=6)&&(b>=6)) {
      printf("Promociono.\n");
    }else{
      printf("Debe recuperar algun parcial.\n");
    }
    break;

  }
printf("El promedio es:%d\n",estado );
  return 0;
}
