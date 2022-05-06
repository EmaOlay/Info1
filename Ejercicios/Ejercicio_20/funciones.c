void printHex(void *dataPtr, int dataSize){
char* aux=(char *)dataPtr;
  for (int i = 0; i < dataSize; i++) {
    printf("%x ",*(aux+i) );
  }
printf("\n");
}

int copiar (char *origen, char *destino){

  FILE *des, *ori;
  int aux,cantRead,cantWrite,i=0;
  char v[80];//80 because it painted
  //--abro o creo el archivo destino--
  des=fopen(destino,"w");
  if (des==NULL) {
    printf("Error al abrir el archivo destino\n");
    return(-1);
  }
  //--abro el archivo origen--
  ori=fopen(origen,"r");
  if (ori==NULL) {
    printf("Error al abrir el archivo origen\n");
    return(-1);
  }
  while (!feof(ori)) {
    //--leo y lleno en v[]
    cantRead=fread(&v[0],sizeof(v[0]),sizeof(v), ori);
    if (cantRead<0) {
      printf("Error al leer en el archivo origen\n");
      return(-1);
    }else{
      printf("cantRead=%d\n",cantRead );
      //--Escribo en dest
      cantWrite= fwrite(v,sizeof(char),cantRead,des);
      if (cantWrite<0) {
        printf("Error al escribir en el archivo destino\n");
        return(-1);
      }else{
        i+=cantWrite;
      }
    }
  }
  //--Cierro
  aux=fclose(ori);
  if (aux!= 0) {
    printf("Error al cerrar el archivo origen\n");
  }
  aux=fclose(des);
  if (aux!= 0) {
    printf("Error al cerrar el archivo destino\n");
  }
  return i;
}
