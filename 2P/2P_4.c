#include "funciones.c"
int eliminarComentarios (char *nombre){
  char nombre_destino[128];
  char nombre_aux[128];
  char * pos_c=NULL;
  int rVal;
  int cont_comentarios=0;
  struct stat info_archivo;
  strcpy(nombre_aux, nombre);
  //cast para los warnings
  pos_c=strstr((const char *) nombre_aux, ".c");
  if (pos_c==NULL) {
    //No es un .c
    return -1;
  }
  //--Abro el archivo origen
    FILE* fp1;
    fp1=fopen(nombre,"r");
    if (fp1==NULL) {
      printf("Error en fopen 1\n");
      return(-1);
    }
    //pongo \0 donde encontre el .c
    *(pos_c)='\0';
    //agrego el .cs
    strcat(nombre_aux, ".cs");
    //verifico
    printf("%s\n", nombre_aux);
    //paso el nombre destino
    strcpy(nombre_destino, nombre_aux);
    //--Abro el archivo destino
      FILE* fp2;
      //sprintf (nombre_destino,"%s.cs", nombre_aux);
      fp2=fopen(nombre_destino,"w");
      if (fp2==NULL) {
        printf("Error en fopen 1\n");
        return(-2);
      }

  //Guardo el tamanio del archivo
  int aux=stat(nombre,&info_archivo);
  //printf("info_archivo.st_size=%d\n",info_archivo.st_size );
  if (aux== -1)
      printf("Error al obtener informacion sobre el archivo\n");
  //--Pido memoria para guardar todo
  char* ptr=(char *) malloc(info_archivo.st_size);
  if (ptr==NULL) {
    //Error pidiendo memoria
    return -4;
  }
  aux=fread(ptr,info_archivo.st_size,1,fp1);
  if (aux<0) {
    printf("Error en fread\n");
    return(-1);
  }
  //printf("%s\n",ptr );
  int comentario_flag=0;
  int i=0;
  for ( i = 0; i < info_archivo.st_size; i++) {
    switch (comentario_flag) {
      case 0:
      //pregunto si empezo un comentario
      if (*(ptr+i)=='/') {
        //printf("Encontre una barra\n");
        if (*(ptr+i+1)=='/' ||*(ptr+i+1)=='*') {

          comentario_flag=1;
          cont_comentarios++;
        }

      }
      break;
      case 1:
      //pregunto si termino un comentario
      if (*(ptr+i)=='\n') {
        comentario_flag=0;
      }
      if ((*(ptr+i)=='*' && *(ptr+i+1)=='/')) {
        comentario_flag=0;
        i+=2;
      }
      break;

      default:
      break;
    }

    if (comentario_flag==0) {
      //-- Lo escribo en el archivo que me dijeron --
      rVal = fwrite ((ptr+i), 1, 1, fp2);
      if (rVal < 0) {
      printf ("Error al escribir en el archivo\r\n");
      return (-1);
      }
    }
    //printf("comentario_flag=%d\t,*(ptr+i)=%c\n", comentario_flag,*(ptr+i));

  }

  //-- Cierro el archivo --
  fclose(fp1);
  fclose(fp2);
  return(cont_comentarios);
}

//gcc -Wall 2P_4.c -o 2P_4.out
int main() {
  //Comentario1
char archivo[]="2P_4.c";
int comentarios_elim=0;
//comentario 2

comentarios_elim=eliminarComentarios (archivo);
/*Comentario random*/
printf("%d\n", comentarios_elim);
  return 0;
}
