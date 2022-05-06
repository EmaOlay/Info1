#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)26)//cantidad de letras
int main (void)
{
char *p;
int i;
//-- Pido memoria dinamicamente. --
p = (char *)malloc (sizeof (*p) * CANT);
if (p == NULL) {
  //Si es NULL no pudo reservar->
  return (-1);
}
//-- Inicializo el vector --
for (i = 0; i < CANT ; i++) {
  *(p + i) = i+65;//+65 o +'A'
}
//-- Imprimo el vector --
for (i = 0; i < CANT ; i++) {
  printf ("%c\r\n", *(p + i));
}
//-- Libero memoria --
free (p);
return (0);
}
