#include "funciones.c"


#define ARCHIVO "lista_anime.txt"


int main() {
  sword_t * vector[500];
  /*for (int i = 0; i < 500; i++) {
    vector[i]=NULL;
  }*/
  int palabras_dist=0;
  palabras_dist=contar_palabras(vector, ARCHIVO);
  printf("palabras_dist=%d\n", palabras_dist);
  for (int i = 0; i < palabras_dist; i++) {
    printf("%s\n", vector[i]->palabra);
  }
  return 0;
}
