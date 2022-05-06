#include "funciones.c"


#define  ARCHIVO "23_06.txt"

int main() {
  char * tablero;
  int fin=0;

  //-- Creo e inicializo--
  tablero=tableroCrear();
  //--Juego hasta llegar al fin de la partida--
  while(!(fin)){
    juegoTablero2(ARCHIVO,tablero,&fin);
  }
  //--libero memoria--
  free(tablero);
  return 0;
  
}
