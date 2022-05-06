#include "funciones.c"

int main() {

  char * tablero;
  int fin=0;

  //-- Creo e inicializo--
  tablero=tableroCrear();
  //--Juego hasta llegar al fin de la partida--
  while(!(fin)){
    juegoTablero(tablero,&fin);
  }
  //--libero memoria--
  free(tablero);
  return 0;
}
