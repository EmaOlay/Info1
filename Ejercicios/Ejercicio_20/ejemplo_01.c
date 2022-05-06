#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int aux;
  struct stat st;

    //--leo la estructura del archivo
    aux=stat("./ejemplo_01.c", &st);
    if (aux<0) {
      printf("Error en fstat\n");
      return(-1);
    }
    printf("El archivo tiene %ld bytes\r\n", st.st_size);
    
  return 0;
}
