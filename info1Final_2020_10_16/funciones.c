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

int agregarInicio (char *nombre, char *texto){
  struct stat buffer;
  int aux=0;
  int salida=-1;

  //--Abro el archivo
  FILE* fp;
  //Guardo el tamanio del archivo para verificaciones
  aux=stat(nombre,&buffer);
  if (aux== -1) {
      printf("Error al obtener informacion sobre el archivo\n");
      //Este error no esta definido en la consigna lo creo yo...
      //nombre es un char *
      fp=fopen(nombre,"w");
      if (fp==NULL) {
        printf("Error en fopen 1\n");
        return(-1);
      }
    }else{
      fp=fopen(nombre,"r+");
      if (fp==NULL) {
        printf("Error en fopen 2\n");
        return(-1);
      }
    }

  //--Pido memoria para guardar todo
  char* ptr=(char *) malloc(buffer.st_size);
  aux=fread(ptr,buffer.st_size,1,fp);
  if (aux<0) {
    printf("Error en fread\n");
    return(-1);
  }
  //Me paro al principio del archivo
  rewind(fp);

  salida=fwrite(texto,1,strlen(texto),fp);
  if (salida<=0) {
    printf("Error en el primer fwrite\n");
  }
  printf("1-Salida=%d\n",salida );
  salida=fwrite(ptr,1,buffer.st_size,fp);
  if (salida<0) {
    printf("Error en el segundo fwrite\n");
  }
  printf("2-Salida=%d\n",salida );
  fclose(fp);
  free(ptr);
  return salida;
}


int verificarEan13_1(char* codigo){
int suma_pares=0;
int suma_impares=0;
int aux=0;

  if (strlen(codigo)!=13) {
    printf("Demasiado largo o corto\n");
    return -1;
  }

  for (int i = 0; i < 13; i++) {

    if (*(codigo+i)<'0'|| *(codigo+i)>'9') {
      printf("%d %c\n",i,*(codigo+i) );
      printf("Me mandaste fruta flaco\n");
      printf("Salu3\n");
      return(-1);
    }
  }

  for (int i = 0; i < 11; i+=2) {
    suma_pares+= *(codigo+i)-'0';
  }
  suma_pares=suma_pares*3;
  for (int i = 1; i < 13; i+=2) {
    suma_impares+= *(codigo+i)-'0';
  }
  aux=suma_pares+suma_impares;
  //printf("Suma pares=%d\n Suma impares=%d\n (aux%%10)=%d\n",suma_pares,suma_impares,(aux%10) );
  if ((aux%10)==*(codigo+12)-'0') {
    printf("Codigo valido!\n");
    return 1;
  }

return(0);
}

int verificarEan13 (char **codigosVect,int codigosCant, int *validos,int *invalidos){
  for (int i = 0; i < codigosCant; i++) {
    if (verificarEan13_1(*(codigosVect+i))==1) {
      *(validos)+=1;
    }else{
      if (verificarEan13_1(*(codigosVect+i))==0) {
        *(invalidos)+=1;
      }else
        return(-1);
    }
  }
  return 0;
}

int enviarInvertido (char *fifoName, char *fileName){
  int aux;
  struct stat buffer;
  //--Abro el archivo
  FILE* fp;
  fp=fopen(fileName,"r+");
  if (fp==NULL) {
    printf("Error en fopen 1\n");
    return(-1);
  }
  aux=stat(fileName,&buffer);
  char* ptr= (char *) malloc(buffer.st_size);
  aux=fread(ptr,1,buffer.st_size,fp);
  if (aux<0) {
    printf("Error en fread\n");
    return(-1);
  }

  int rVal;
  int fd;
      //-- Creo el nodo fifo --
      rVal = mknod (fifoName, S_IFIFO | 0666, 0);
      if (rVal == -1) {
        perror ("Error mknod");
        //return (-1);
      }
      //-- Abro la fifo como lectura --
      printf ("Abro la FIFO como Escritura\r\n");
      fd = open (fifoName, O_WRONLY);
      for (int i = buffer.st_size-1; i >= 0; i--) {
          rVal = write (fd, (ptr+i), 1);
          if (rVal > 0) {
            printf ("%c", *(ptr+i));
          }
        }
        //printf ("Se escribieron %d bytes en la FIFO\r\n", rVal);

  fclose(fp);
  close(fd);
  return 0;
}
