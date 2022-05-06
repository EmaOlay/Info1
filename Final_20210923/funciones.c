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
#include <time.h>


int leer_parseo(char * archivo,float* vector1,int* vector2){

  //--Abro el archivo
  FILE* fp;
      fp=fopen(archivo,"r");
      if (fp==NULL) {
        printf("Error en fopen\n");
        return(-1);
      }

    //siempre son 5 argumentos y los primeros 4 son floats
      for (int i = 0; i < 3; i++) {
        fscanf(fp,"%f",(vector1 + i));
        //printf("%f\n",*(vector1 + i) );
      }
    //el quinto lo levanto solari
    fscanf(fp,"%d/%d",(vector2),(vector2+1));
    //printf("%d\n",*(vector2) );
  fclose(fp);
  return(0);
}


float promedio_columna(float * ptr,int columnas,int cant){
  float acum=0;
  float promedio=0;
  for (int i = 0; i < cant; i++) {
    //printf("ptr[%d]=%f\n",i*columnas,*(ptr+i*columnas) );
    acum+= *(ptr+i*columnas);
  }
  //printf("acum=%f\n", acum);

  promedio=acum/cant;
  //printf("promedio=%f\n", promedio);
  return(promedio);
}
