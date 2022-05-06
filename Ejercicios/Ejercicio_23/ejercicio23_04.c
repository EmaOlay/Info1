#include "funciones.c"

#define  ARCHIVO "23_03.txt"


int main() {
  int filas=2;
  int columnas=3;
  int *m_escribir;
  int m_leer[2][3];
  m_escribir=matrizCrear(filas,columnas);
  //-- Inicializo la matriz en algo distinto--
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      *(m_escribir + (i*columnas)+j)=69;//for the memes
    }
  }
  matrizEscribir(ARCHIVO,m_escribir,filas,columnas);
  free(m_escribir);
  matrizLeer(ARCHIVO,&m_leer[0][0],filas,columnas);
  matrizImprimir(&m_leer[0][0],filas,columnas);
  return 0;
}
