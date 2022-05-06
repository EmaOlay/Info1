#include <stdio.h>
#include <stdlib.h>

int main (void){
char *p;
int i,cant;
printf("Cuantas letras desea ingresar?\n");
scanf("%d", &cant);
//-- Pido memoria dinamicamente. --
p = (char *)malloc (sizeof (*p) * cant);
if (p == NULL) {
  //Si es NULL no pudo reservar->
  return (-1);
}
//-- Inicializo el vector --
for (i = 0; i < cant ; i++) {
  scanf("%c", p+i);
  printf("Ingrese una letra\n");
  scanf("%c", p+i);

}
//-- Imprimo el vector --
for (i = cant; i >= 0 ; i--) {
  printf ("%c\r\n", *(p + i));
}
//-- Libero memoria --
free (p);
return (0);
}
