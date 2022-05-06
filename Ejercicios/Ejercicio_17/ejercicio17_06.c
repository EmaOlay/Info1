#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Para probar:
Tres tristes tigres,tragaban trigo en un trigal,en tres tristes trastos,tragaban trigo tres tristes tigres.
*/

int analizaString (char *dataPtr, int *palabrasCant, int *caracteresCant){
int i=0,j=0, flag_num=0;
char palabra_aux[20];
  while (*(dataPtr+i)!='\0') {
    palabra_aux[j]= *(dataPtr+i);
    //esto lo hago porque la primer palabra no la detecto con el if siguiente
    if (*(palabrasCant)==0) {
      *(palabrasCant)=1;
    }
    if (*(dataPtr+i+1)== ' ' || *(dataPtr+i+1)==',' || *(dataPtr+i+1)=='.') {
      //Agregar un palabra_aux[j-1] para verificar que sea una palabra?
      if ((*(dataPtr+i)>='a'&&*(dataPtr+i)>='z')||(*(dataPtr+i)>='A'&& *(dataPtr+i)>='Z')) {
        memset(palabra_aux,0,strlen(palabra_aux));
        j=0;
        *(palabrasCant)+=1;
      }

    }
    //Check caso excepcional termina sin puntuacion
    if (*(dataPtr+strlen(dataPtr)-1)== '\0') {
      *(palabrasCant)=*(palabrasCant)-1;
    }
    //checkeo por numeros unicamente pero deberia checkear otras cosas
    if (*(dataPtr+i)>='0' && *(dataPtr+i)<='9') {
      flag_num=1;
    }
    j++;
    i++;
  }
*(caracteresCant)=i;
  if (flag_num==1) {
    return -1;
  }else{
    return 0;
  }

}

int main() {

char string[150];
int var,cant_pal,cant_cara;

printf("Ingrese un string\n");
scanf("%149[^\n]", string);
var =analizaString(string,&cant_pal,&cant_cara);
printf("La funcion analizaString devolvio:%d\n",var);
printf("La cantidad de palabras fue:%d\n",cant_pal);
printf("Y la cantidad de caracteres fue:%d\n", cant_cara);

  return 0;
}
