#include "funciones.c"


int main() {
  int *p=NULL;
  int filas=2, columnas=3;
  p=matrizCrear(filas,columnas);
  if (p==NULL) {
    printf("FRUTA\n");
    return (-1);
  }else{
    matrizImprimir(p,filas,columnas);
  }
  free(p);
  return 0;
}
