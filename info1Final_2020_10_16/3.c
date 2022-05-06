#include "funciones.c"


int main() {

  char* fifoName= "miFifo";
  char* fileName="lista_anime.txt";
  enviarInvertido (fifoName, fileName);
  return 0;
}
