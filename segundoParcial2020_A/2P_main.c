#include "funciones.c"

#define ARCHIVO "lista_anime.txt"

//El 1 se compila: gcc -Wall 2P_main.c -o 2P_main.out -lm
int main() {
  int tamanio=300;
  dividirArchivos(ARCHIVO,tamanio);
  return 0;
}
