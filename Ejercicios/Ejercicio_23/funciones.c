#include <stdio.h>
#include <stdlib.h>
void matrizImprimir(int *p, int filas, int columnas){
  for (int i = 0; i < filas; i++) {//recorro una columna
    for (int j = 0; j < columnas; j++) {//recorro una por una las filas de la columna
      printf("El contenido de la columna %d, fila %d es:\n",i,j );
      printf("%d\n",*(p+(i*columnas)+j) );
    }
  }
}

int * matrizCrear(int filas, int columnas){
  int *m;
  m=(int *) malloc(filas*columnas*sizeof(int));
  if(m==NULL){
    printf("Error en malloc\n");
    return NULL;
  }
  //-- Inicializo la matriz--
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      *(m + (i*columnas)+j)=0;
    }
  }
  return m;
}

int matrizEscribir(char* nombre, int*p, int filas, int columnas){
  FILE* f;
  int cantWrite;
  //--abro el archivo--
  f=fopen(nombre,"w");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //--Escribo--
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cantWrite= fwrite((p+(i*columnas)+j),sizeof(int),1,f);
      printf("i=%d;j=%d;%x\n",i,j,*(p+(i*columnas)+j));
      printf("Cantwrite:%d\n",cantWrite );
      if (cantWrite<0) {
        printf("Error al escribir en el archivo destino\n");
        return(-1);
      }
    }
  }
  //--Cierro
  cantWrite=fclose(f);
  if (cantWrite!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}

int matrizLeer(char*nombre,int*p,int filas, int columnas){
  FILE* f;
  int cantRead;
  //--abro el archivo--
  f=fopen(nombre,"r");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }

  //--Leo--
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cantRead= fread((p+(i*columnas)+j),sizeof(int),1,f);
      if (cantRead<0) {
        printf("Error al leer el archivo destino\n");
        return(-1);
      }
    }
  }
  //--Cierro
  cantRead=fclose(f);
  if (cantRead!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}

char * tableroCrear(void){
//funcion que crea el tablero para el ta te ti
    char *m;
    m=(char *) malloc(3*3*sizeof(char));
    if(m==NULL){
      printf("Error en malloc\n");
      return NULL;
    }
    //-- Inicializo la matriz--
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        *(m + (i*3)+j)=' ';
      }
    }
    return m;
}

int checkFin(char * tablero){
  int cont=0;

  //check victoria
  if (tablero[0]==tablero[1] && tablero[1]==tablero[2]) {
    if (tablero[0]!=' ') {
      printf("Ganaron los %c\n",tablero[0] );
      return 1;
    }
  }
  if (tablero[3]==tablero[4] && tablero[4]==tablero[5]) {
    if (tablero[3]!=' ') {
      printf("Ganaron los %c\n",tablero[3] );
      return 1;
    }
  }
  if (tablero[6]==tablero[7] && tablero[7]==tablero[8]) {
    if (tablero[6]!=' ') {
      printf("Ganaron los %c\n",tablero[6] );
      return 1;
    }
  }
  if (tablero[0]==tablero[3] && tablero[3]==tablero[6]) {
    if (tablero[0]!=' ') {
      printf("Ganaron los %c\n",tablero[0] );
      return 1;
    }
  }
  if (tablero[1]==tablero[4] && tablero[4]==tablero[7]) {
    if (tablero[1]!=' ') {
      printf("Ganaron los %c\n",tablero[1] );
      return 1;
    }
  }
  if (tablero[2]==tablero[5] && tablero[5]==tablero[8]) {
    if (tablero[2]!=' ') {
      printf("Ganaron los %c\n",tablero[2] );
      return 1;
    }
  }
  if (tablero[0]==tablero[4] && tablero[4]==tablero[8]) {
    if (tablero[0]!=' ') {
      printf("Ganaron los %c\n",tablero[0] );
      return 1;
    }
  }
  if (tablero[2]==tablero[4] && tablero[4]==tablero[6]) {
    if (tablero[2]!=' ') {
      printf("Ganaron los %c\n",tablero[2] );
      return 1;
    }
  }
  //check de empate
  for (int i = 0; i < 9; i++) {
    if(tablero[i]==' '){//no es empate aun
      cont+=1;
    }
  }
  if (cont==0) {
    printf("Empate!\n");
    return 1;
  }
  return 0;
}

void tableroImprimir(char * tablero){
if (sizeof(tablero)!=8) {
    printf("Solo usar para imprimir tablero\n");
    }else{
    printf("%c|%c|%c\n",tablero[0],tablero[1],tablero[2] );
    printf("------\n");
    printf("%c|%c|%c\n",tablero[3],tablero[4],tablero[5] );
    printf("------\n");
    printf("%c|%c|%c\n",tablero[6],tablero[7],tablero[8] );
    }

}

void juegoTablero(char * tablero,int * fin){
  int movimiento=-1;
  //pido un movimiento valido al jugador 1
  do {
    printf("Ingrese una pocision Jugador 1\n");
    scanf("%d",&movimiento );
  } while((*(tablero+movimiento)=='X' || *(tablero+movimiento)=='O')||(movimiento<0 || movimiento>8));
  //Cargo el movimiento valido
  *(tablero+movimiento)='X';
  //--Imprimo el tablero--
  tableroImprimir(tablero);
  //--checkeo el fin de la partida--
  *fin=checkFin(tablero);
  if (*fin ==1) {
    return;
  }
  //pido un movimiento valido al jugador 2
  do {
    printf("Ingrese una pocision Jugador 2\n");
    scanf("%d",&movimiento );
  } while((*(tablero+movimiento)=='X' || *(tablero+movimiento)=='O')||(movimiento<0 || movimiento>8));
  //Cargo el movimiento valido
  *(tablero+movimiento)='O';
  //--Imprimo el tablero--
  tableroImprimir(tablero);
  //--checkeo el fin de la partida--
  *fin=checkFin(tablero);
  if (*fin ==1) {
    return;
  }
}

int tableroEscribir(char* nombre, char * tablero){
  FILE* f;
  int cantWrite;
  //--abro el archivo--
  f=fopen(nombre,"a");
  if (f==NULL) {
    printf("Error al abrir el archivo\n");
    return(-1);
  }
  //--Escribo--
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cantWrite= fwrite((tablero+(i*3)+j),sizeof(char),1,f);
      if (cantWrite<0) {
        printf("Error al escribir en el archivo destino\n");
        return(-1);
      }
    }
  }
  cantWrite= fwrite("\r\n",sizeof(char),2,f);
  //--Cierro
  cantWrite=fclose(f);
  if (cantWrite!= 0) {
    printf("Error al cerrar el archivo\n");
  }
  return 0;
}

void juegoTablero2(char* nombre,char * tablero,int * fin){
  int movimiento=-1;
  //pido un movimiento valido al jugador 1
  do {
    printf("Ingrese una pocision Jugador 1\n");
    scanf("%d",&movimiento );
  } while((*(tablero+movimiento)=='X' || *(tablero+movimiento)=='O')||(movimiento<0 || movimiento>8));
  //Cargo el movimiento valido
  *(tablero+movimiento)='X';
  //--Imprimo el tablero--
  tableroImprimir(tablero);
  tableroEscribir(nombre,tablero);
  //--checkeo el fin de la partida--
  *fin=checkFin(tablero);
  if (*fin ==1) {
    return;
  }
  //pido un movimiento valido al jugador 2
  do {
    printf("Ingrese una pocision Jugador 2\n");
    scanf("%d",&movimiento );
  } while((*(tablero+movimiento)=='X' || *(tablero+movimiento)=='O')||(movimiento<0 || movimiento>8));
  //Cargo el movimiento valido
  *(tablero+movimiento)='O';
  //--Imprimo el tablero--
  tableroImprimir(tablero);
  tableroEscribir(nombre,tablero);
  //--checkeo el fin de la partida--
  *fin=checkFin(tablero);
  if (*fin ==1) {
    return;
  }
}
