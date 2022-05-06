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


typedef struct {
char palabra[20];
int count;
} sword_t;

int contar_palabras(sword_t **a, char *archivo){
  //a viene con todo en cero al principio
  int i=0;//indice palabra
  int j=0;//indice array de punteros
  char buffer[20];
  int la_encontre=0;
  //--Abro el archivo
  FILE* fp;
      fp=fopen(archivo,"r");
      if (fp==NULL) {
        printf("Error en fopen\n");
        return(-1);
      }

  while(!feof(fp)){

    //condicion de newline    //aa HOLA mundo
    buffer[i]=fgetc(fp);

    if(buffer[i]=='\n' || (buffer[i])== ' '){

      buffer[i]='\0';
      //Recorro todas mis struct
      for (int x = 0; x < j; x++) {
        if(strcmp((*(a+x))->palabra,buffer)==0){
          (*(a+x))->count++;
          la_encontre=1;
          break;
        }else{
          la_encontre=0;
        }
      }
      if (la_encontre==0) {
        *(a+j)=(sword_t *)malloc(sizeof(sword_t));
        //(ptr+j)=(sword_t *)malloc(sizeof(sword_t));
        if (*(a+j)==NULL) {
          printf("Error al pedir memoria\n");
          return -1;
        }
        strcpy((*(a+j))->palabra,buffer);
        (*(a+j))->count=1;
        j++;
        la_encontre=1;
      }
      i=0;
    }else{
      i++;
    }
  }
  return j;
}
