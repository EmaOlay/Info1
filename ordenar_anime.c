#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "lista_anime.txt"

int main() {
  int CANT=0;
  char aux='a';
  char temp[100];
  char **p;
  char* temporal;

    FILE* fp;
    fp=fopen(ARCHIVO,"r");
    if (fp==NULL) {
      printf("Error en fopen\n");
    }
    while (!(feof(fp))) {
      aux=(char)fgetc(fp);
      //printf("%c\n",aux );
      if(aux==';'){
        CANT++;
      }
    }
    printf("La cantidad es:%d\n",CANT);
    p=(char**)malloc(sizeof(char*)*CANT);
    if (p==NULL) {
      printf("Error pidiendo memoria\n");
      return(-1);
    }
    //p[cant]={direccionlin1,direccionlin2,...};
    rewind(fp);
    for (int i = 0; i < CANT; i++) {
      fgets(temp,(int)sizeof(temp),fp);
      if (temp!=NULL) {
        *(p+i)=(char*)malloc(sizeof(char)*(strlen(temp)+1));
        if(*(p+i)==NULL){
          printf("Error pidiendo memoria\n");
          return (-1);
        }
        strcpy(*(p+i), temp);
      }
    }
    /* Verificacion de los renglones del archivo original
    for (int i = 0; i < CANT; i++) {
      printf("%s\n",*(p+i) );
    }
    */
    printf("--------\n");
  //Burbujeo
  for (int i = 0;i < CANT; i++){
    for (int j = 0; j< CANT-1; j++){
      if (strcmp(*(p+j),*(p+j+1))>0){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
      temporal= *(p+j);
      *(p+j)=*(p+j+1);
      *(p+j+1)=temporal;
      }
    }
  }
  for (int i = 0; i < CANT; i++) {
    printf("%s",*(p+i) );
  }
  if (fclose(fp)!=0) {
    printf("Error al cerrar el archivo\n");
  }
  return CANT;
}
