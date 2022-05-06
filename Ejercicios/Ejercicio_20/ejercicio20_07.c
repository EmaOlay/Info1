#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"

#define ARCHIVO_ORIGEN "/home/ema/Desktop/emaolay/lista_anime.txt"
#define ARCHIVO_DESTINO "/home/ema/Desktop/emaolay/Ejercicios/Ejercicio_20/20_07.txt"

int main() {
  int a;
  a=copiar(ARCHIVO_ORIGEN,ARCHIVO_DESTINO);
  printf("La cantidad de renglones copiados fueron:%d\n", a);
  return 0;
}
