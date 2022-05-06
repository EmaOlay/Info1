#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
//"/home/ema/Desktop/emaolay/lista_anime.txt"


int main(int argc, char const *argv[]) {
  FILE* f;
  int aux;
  //int i=0;
  //int cantRead;
  //char nada;
  struct stat a;
  if (argc>2) {
    printf("Parametros de mas!\n");
    return(-1);
  }
  if (argc<2) {
    printf("Parametros de menos!\n");
    return (-1);
  }
  //--abro el archivo--
  f=fopen(argv[1],"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  stat(argv[1],&a);
  printf("El archivo %s pesa: %ld\n", argv[1],a.st_size);
  //resolvelo con stat campeon!
  /*
  while (!feof(f)) {
    cantRead=fread(&nada,sizeof(char),1, f);
    if (cantRead<0) {
      printf("Error al leer en el archivo\n");
      return(-1);
    }else{
      i++;
    }
   }
   */
  //--Cierro
  aux=fclose(f);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;

}
