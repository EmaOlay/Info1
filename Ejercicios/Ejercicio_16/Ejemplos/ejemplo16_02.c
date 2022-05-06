#include <stdio.h>
#include <stdlib.h>
#define CANT ((int) 10)

int main (void){
int *p, *pBack;
int cantTotal, i;
int cantUsada;
    //-- Pido memoria para CANT elementos --
    cantTotal = CANT;
    cantUsada = 0;
    p = (int*)malloc (sizeof (*p) * cantTotal);
    if (p == NULL) {
      return (-1);
    }
    //-- Inicializo la zona de memoria asignada con i--
    for (i = cantUsada; i < cantTotal; i++) {
      *(p + i) = i;
      cantUsada++;
    }
//-- Pido memoria para CANT elementos mas--
    pBack = (int*)realloc (p, sizeof (*p) * (cantTotal + CANT));
    if (pBack != NULL) {
//-- Realloc ok --
//-- Hay cantTotal + CANT elementos --
    cantTotal += CANT;
    p = pBack;
    }
//-- Inicializo la zona de memoria asignada con uno--
    for (i = cantUsada; i < cantTotal; i++) {
      *(p + i) = i;
      cantUsada++;
    }
//-- Imprimo el vector utilizado, en este caso es todo --
    for (i = 0; i < cantUsada; i++) {
      printf ("%d\r\n", *(p + i));
    }
//-- Libero memoria --
    free (p);
    return (0);
}
