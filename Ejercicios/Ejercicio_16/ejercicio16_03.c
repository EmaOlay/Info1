#include <stdio.h>
#include <stdlib.h>

int main (void){
char *p, *pBack;
int cantTotal=0,flag;
char aux;
    //-- Pido memoria para 1 elemento y luego ajusto
    cantTotal = 1;
    p = (char*)malloc (sizeof (*p) * cantTotal);
    if (p == NULL) {
      return (-1);
    }
    //pido la primer letra y me lajuego a que no sea '!'
    printf("Ingrese una letra\n");
    scanf("%c", p);
    //Mientras no me ingresen '!' ejecuto
    while (flag!=1) {
      //printf("Entre al while\n");

      printf("Ingrese una letra\n");
      scanf("%c", &aux);
      scanf("%c", &aux);
      if (aux=='!') {
        flag=1;
      }
      //-- Pido memoria para 1 elemento mas--

          pBack = (char*)realloc (p, sizeof (*p) * (cantTotal+1));
          if (pBack != NULL) {
      //-- Realloc ok --
          p = pBack;
          *(p+cantTotal)=aux;
          cantTotal ++;
          }
    }

//-- Imprimo el vector

    for (int i = 0; i < cantTotal; i++) {
      printf ("%c\r\n", *(p + i));
    }
//-- Libero memoria --
    free (p);
    return (0);
}
