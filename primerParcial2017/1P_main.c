#include <stdio.h>
//#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "1P_funciones.c"

int main() {
  //--Ejercicio 1-----
  /*
  float tarifa[]={4.50,3.60,3.15,2.70};
  int viajes[]={0,20,30,40};
  float prom=pasaje_promedio(30,tarifa,viajes,(int)sizeof(tarifa)/sizeof(float));
  printf("El promedio del pasaje es: %g\n", prom);
  */


  //--Ejercicio 2----
  //char string[]="HOLA MUNDO";
  //unsigned char string[]="HOLA Ñ NDO";
  //unsigned char string[1];
  //string[0]=165;
  //printf("La cantidad de letras es: %d\n", rot_13(string));
  //printf("La frase quedo: %s\n", string);
  unsigned char count;
    for(count=32; count< 255; count+=1)
    {
        printf("  %3d - %c",count,count);
        if(count % 6==0)
            printf("\n");
    }

  //--EJ3-----
  /*
  //char cbu[]="";
  printf("%d\n", cbu_validar(cbu));
  */
  return 0;
}
