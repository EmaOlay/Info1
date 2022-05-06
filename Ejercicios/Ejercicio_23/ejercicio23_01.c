#include "funciones.c"

#define FILAS ((int) 3)
#define COLUMNAS ((int) 3)

int main() {
  int *m;
  int i, j;
  int c=0;
  m=(int *) malloc(FILAS*COLUMNAS*sizeof(*m));
  if(m==NULL){
    printf("Error en malloc\n");
    return (-1);
  }
  //-- Inicializo la matriz--
  for (i = 0; i < FILAS; i++) {
    for ( j = 0; j < COLUMNAS; j++) {
      *(m + (i*COLUMNAS)+j)=c;
      c++;
    }
  }
  matrizImprimir(m, FILAS, COLUMNAS);
  return 0;
}
