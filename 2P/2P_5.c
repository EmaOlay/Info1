#include "funciones.c"

//gcc -Wall 2P_5.c -o 2P_5.out
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    kill(atoi(argv[i]),SIGKILL);
  }
  return 0;

}
