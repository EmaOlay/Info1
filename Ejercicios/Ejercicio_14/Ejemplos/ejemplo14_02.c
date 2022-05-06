#include <stdio.h>

int main(int argc, char const *argv[]) {
  int m5[]= {0, 5, 10, 15, 20, 25, 30, 35, 40, 45};
  int num;

  //Ingreso numero
  printf("Ingrese numero\n");
  scanf("%d", &num);

  if ((num>=0)&&(num<=9)) {
    printf("El resultado es: %d\r\n", m5[num]);
  } else {
    printf("Imposible calcular\n");
  }
  return 0;
}
