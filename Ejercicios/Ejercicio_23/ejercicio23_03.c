#include "funciones.c"


#define  ARCHIVO "23_03.txt"

int main() {
  int *ptr;
  int filas=2;
  int columnas=3;
  ptr=matrizCrear(filas,columnas);
  matrizEscribir(ARCHIVO,ptr,filas,columnas);
  return 0;
}
