#include "funciones.c"


int main() {
  char * matriz;
  matriz=matrizCrear(3, 3);
  sopaLeer ("NADA", (void **)&matriz);
  return 0;
}
