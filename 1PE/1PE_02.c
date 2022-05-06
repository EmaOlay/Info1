#include <stdio.h>
#include <string.h>

/*
Emanuel Olay
Leg:1568656
gcc -Wall 1PE_02.c -o 1PE_02.out
*/
int contarPalabras(char* str, char* palabracontar){
  int j=0;
  int cant=0;
  while (*(str+j)!='\0') {
      // comparo

      if (strstr(str+j, palabracontar) == str+j) {

          cant++;
          j+= strlen(palabracontar);

      }
      else{
        j++;
      }
  }
  if (cant>0) {
    return cant;
  }
  return -1;
}

int main() {
  /*
  char string[]="El zorro pepe es un crack";
  char buscar[]="zorro";
  */
  /*
  char string[]="El zorro zorro zorro pepe es un crack";
  char buscar[]="zorro";
  */
  /*
  char string[]="El gato pepe es un crack";
  char buscar[]="zorro";
  */
  /*
  char buscar[]="El gato pepe es un crack";
  char string[]="zorro";
  */
  char buscar[]="\0";
  char string[]="\0";
  printf("cant=%d\n", contarPalabras(string, buscar));
  return 0;
}
