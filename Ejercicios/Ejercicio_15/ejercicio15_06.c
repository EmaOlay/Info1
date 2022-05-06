#include <stdio.h>
#define  CANT ((int) 50)


int myHexa (char *dataPtr){
  int i=0;
  printf("El string en hexa es:\n");
  while (*(dataPtr+i)!='\0') {
    //printf("la variable i vale:%d\n", i);
    printf("%x ",*(dataPtr+i) );
    i++;
  }
  printf("\n");
  return i;
}

int main() {
  int a;
  char string[CANT];
  printf("Ingrese un string\n");
  scanf("%s", string);
  a=myHexa(string);
  printf("El string es %d caracteres largo.\n", a);
  return 0;
}
