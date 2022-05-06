#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)10)
int main (void)
{
int *p;
int i;
//-- Pido memoria dinamicamente. --
p = (int *)malloc (sizeof (*p) * CANT);
if (p == NULL) {
  return (-1);
}
//-- Inicializo el vector --
for (i = 0; i < CANT ; i++) {
  *(p + i) = i;
}
//-- Imprimo el vector --
for (i = 0; i < CANT ; i++) {
  printf ("%d\r\n", *(p + i));
}
//-- Libero memoria --
free (p);
return (0);
}
