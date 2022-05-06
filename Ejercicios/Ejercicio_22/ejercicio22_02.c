#include <stdio.h>
#include <stdlib.h>

//"/home/ema/Desktop/emaolay/lista_anime.txt"
int main(int argc, char const *argv[]) {
  FILE *des, *ori;
  int cantRead,cantWrite,i=0;
  char v[80];//80 because it painted
  //--abro o creo el archivo destino--
  des=fopen(argv[2],"w");
  if (des==NULL) {
    printf("Error al abrir el archivo destino\n");
    return(-1);
  }
  //--abro el archivo origen--
  ori=fopen(argv[1],"r");
  if (ori==NULL) {
    printf("Error al abrir el archivo origen\n");
    return(-1);
  }
  while (!feof(ori)) {
    //--leo y lleno en v[]
    cantRead=fread(&v[0],sizeof(v[0])*80,1, ori);
    if (cantRead<0) {
      printf("Error al leer en el archivo origen\n");
      return(-1);
    }else{
      //--Escribo en dest
      cantWrite= fwrite(v,sizeof(char)*80,1,des);
      if (cantWrite<0) {
        printf("Error al escribir en el archivo destino\n");
        return(-1);
      }else{
        i++;//cuento renglones because it painted
      }
    }
  }
  //--Cierro
  int aux=fclose(des);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  //--Cierro
  aux=fclose(ori);
  if (aux!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}
