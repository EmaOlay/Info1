#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//--------Version vieja
int reemplazarPalabra(char *dataPtr, char *palabraBuscar, char *palabraNueva){
  int i=0;
  int res=0;
  if (strlen(palabraBuscar)!=strlen(palabraNueva)) {//Tamanio check
    return -1;
  }
  if ((*palabraBuscar=='\0')&&(*palabraNueva=='\0')) {
    return -2;
  }
  while (*(dataPtr+i)!='\0') {

    if (strncmp(dataPtr+i,palabraBuscar,strlen(palabraNueva)-1)==0) {
      strncpy(dataPtr+i,palabraNueva,strlen(palabraNueva)-1);
      res++;
    }
    i++;
  }
  return res;
}


int main() {


  char string[]="El perro pepe es un crack.";
  char string_buscar[]="perro";
  char string_nuevo[]="algo";
  int cant=0;

  /*
  char string[100];
  char string_buscar[15];
  char string_nuevo[15];
  char fin_basura;
  int cant=0;
  //pido string
  printf("Ingrese un string\n");
  scanf("%99[^\n]s", string);
  scanf("%c", &fin_basura);
  //pido string a cambiar
  printf("Ingrese un string a buscar\n");
  scanf("%15[^\n]s", string_buscar);
  scanf("%c", &fin_basura);
  //pido string nuevo
  printf("Ingrese un string para cambiar\n");
  scanf("%15[^\n]s", string_nuevo);
  scanf("%c", &fin_basura);
  */
  cant=reemplazarPalabra(ptr_string,string_buscar,string_nuevo);
  printf("La cantidad de palabras reemplazadas fue:%d\n", cant);
  printf("%s\n", string);
  return 0;
}
