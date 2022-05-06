#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int invertir(char *dataPtr){
  int i=0;
  char aux;
  while (i<strlen(dataPtr)/2) {
    aux= *(dataPtr+(int) strlen(dataPtr)-i-1);//guardo el ultimo
    *(dataPtr+strlen(dataPtr)-i-1)=*(dataPtr+i);//el ultimo lo piso con el primero
    *(dataPtr+i)=aux;//el primero lo piso con el ultimo
    i++;
  }
  return(strlen(dataPtr));
}

int main() {
  int j=0;
  char frase[]="Hola como te va";
  char *ptr_aux_aux;
  char *ptr_aux=NULL;
  char frase_aux[255];
  //recorro buscando espacios
  for (int i = 0; i < strlen(frase)+1; i++) {

      if (frase[i]==' ') {
        //encontre un espacio pido memoria suficiente para guardar
        ptr_aux_aux = (char*)realloc (ptr_aux,sizeof(char)*(i-j)+2);
        if (ptr_aux_aux == NULL) {
          printf("Error pidiendo memoria\n");
          free(ptr_aux);
          return (-1);
        }else{ptr_aux=ptr_aux_aux;}
        //copio en lo que pedi
        memcpy(ptr_aux,&frase[j],(i-j));
        *(ptr_aux+((i-j)))=' ';
        *(ptr_aux+((i-j)+1))='\0';
        //invierto el que pedi
        memcpy(&frase_aux[strlen(frase)-i+1],ptr_aux,strlen(ptr_aux));
        j=i+1;
      }

      if (frase[i]=='\0') {
        //encontre un espacio pido memoria suficiente para guardar
        ptr_aux_aux = (char*)realloc (ptr_aux,sizeof(char)*(i-j)+2);
        if (ptr_aux_aux == NULL) {
          printf("Error pidiendo memoria\n");
          free(ptr_aux);
          return (-1);
        }else{ptr_aux=ptr_aux_aux;}
        *(ptr_aux+strlen(ptr_aux)+1)=' ';
        //copio en lo que pedi
        memcpy(ptr_aux,&frase[j],(i-j));
        *(ptr_aux+((i-j)))=' ';
        *(ptr_aux+((i-j)+1))='\0';
        //invierto el que pedi
        memcpy(&frase_aux[strlen(frase)-i+1],ptr_aux,strlen(ptr_aux));
        j=i+1;
      }

  }
  printf("La frase:%s\n",frase );
  for (int i = 1; i <25; i++) {
    printf("%c",frase_aux[i] );
  }
  printf("\n");
  //printf("La frase aux:%s\n",frase_aux );
  free(ptr_aux);
  return 0;
}
