#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>


int sopaLeer (char *archivo, void **dataPtr){

  /*
  FILE* fp;
  //--Abro el archivo
    fp=fopen(archivo,"r");
    if (fp==NULL) {
      printf("Error en fopen\n");
      return(-1);
    }
  */
  return 0;
}

char * matrizCrear(int filas, int columnas){
  char *m;
  m=(char *) malloc(filas*columnas*sizeof(*m));
  if(m==NULL){
    printf("Error en malloc\n");
    return NULL;
  }
  //-- Inicializo la matriz--
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      *(m + (i*columnas)+j)=0;
    }
  }
  return m;
}
