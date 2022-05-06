#include "1P_funciones.c"

int main() {


  int n=33;
  int res=0;


  /*
  int vec1[]={11,12,13,14};
  int tamanio1=sizeof(vec1)/sizeof(int);
  res=insertarInt(vec1,tamanio1,n, 1);
  printf("Pruebo insertar al final\n");
  printf("El numero eliminado fue:%d\ny el vector quedo:\n",res );
  for (size_t i = 0; i < tamanio1; i++) {
    printf("%d\t",vec1[i] );
  }*/
  printf("\n");
  int vec2[]={11,12,13,14,15};
  int tamanio2=sizeof(vec2)/sizeof(int);
  printf("Pruebo inserta al principio\n");
  res=insertarInt(vec2,tamanio2,n, 0);
  printf("El numero eliminado fue:%d\ny el vector quedo:\n",res );
  for (size_t i = 0; i < tamanio2; i++) {
    printf("%d\t",vec2[i] );
  }
  printf("\n");
  return 0;
}
