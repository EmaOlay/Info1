#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>


void showbits( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

void convertir_a_string(int * dataPtr, int cant){
  int i;
  int* ptr_aux=(int *) malloc(sizeof(*dataPtr)*cant);
  if (ptr_aux!=NULL) {
    for (i = 0; i < cant; i++) {
      *(ptr_aux+i)=*(dataPtr+i);
    }
    //Asumo que de los 32 bits de cada int quieren que me quede con los 8 segundos
    for (i = 0; i < cant; i++) {
      //Desplazo 8 para perder los 8 primeros y piso todo lo que no son los 8
      //segundos con 0
      *(ptr_aux+i)=(*(ptr_aux+i)>>8);
      //showbits(*(dataPtr+i));
      *(ptr_aux+i)=(*(ptr_aux+i)&0xFF);
      //showbits(*(dataPtr+i));
      printf("%c", *(ptr_aux+i));
    }
    memcpy(dataPtr,ptr_aux,sizeof(*dataPtr)*cant);
    free(ptr_aux);
  }

}

int nvo_nombre (char * original, char * nuevo){
  char agregado[]="_decrypt";
  int cant=strlen(original);
  //printf("%d\n",strlen(original) );
  int j = 0;
  if (nuevo!= NULL) {
    //copio todo el original al nuevo
    strcpy(nuevo,original);
    for (int i = 0; i < cant; i++) {
      if (*(original+i)=='.') {
        j=i;
      }
    }

    if (j!=0) {
      //Si encontre el punto piso todo del punto en adelante con agregado y luego desde ahi la extension .txt
      strcpy((nuevo+j),agregado);
      strcat(nuevo,original+j);
    }else{
      strcat(nuevo,agregado);
    }
  }

  return 0;
}


int lectura (char * nombre, int ** ptrptr){
  int papa;
  int cant=0;
  int * vector=NULL;
  int *aux=NULL;
  FILE* fp=fopen(nombre,"r");
  if (fp==NULL) {
    printf("Error en fopen\n");
    return(-1);
  }

  while (!feof(fp)) {

  int rVal=fread(&papa,sizeof(papa),1,fp);
    if (rVal>0) {
      cant++;
      aux=(int *) realloc(vector,sizeof(*vector)*cant);

      if (aux!=NULL) {
        vector=aux;
        *(vector+cant-1)=papa;
      }else{
        * ptrptr=vector;
        printf("Error agregando memoria\n");
        return -1;
      }
    }

  }
  for (int i = 0; i < cant; i++) {
    printf("%d\n",*(vector+i) );
  }
  if (cant==0) {
    return -1;
  }
  * ptrptr=vector;
  fclose(fp);
  return cant;
}
