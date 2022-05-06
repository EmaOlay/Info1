#include "funciones.c"


#define NOMBRE "3P_b.bin"


int main() {
  int * ptr;
  int vector[]={30,31,32,3,34,5,98,101};
  FILE* fp=fopen(NOMBRE,"w");
  if (fp==NULL) {
    printf("Error en fopen\n");
    return(-1);
  }
  fwrite(vector,sizeof(vector),1,fp);
  fclose(fp);
  lectura (NOMBRE,&ptr);
  free(ptr);
  return 0;
}
