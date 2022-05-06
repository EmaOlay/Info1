#include <stdio.h>
#include <string.h>


int cuitValida(char *cuit){
  int j=0;
  int secuencia[]={5,4,3,2,7,6,5,4,3,2};
  int acumulacion=0,resultado=0;
  int l=strlen(cuit);
  if (l!=11) {
    return (-1);
  }
  for (int i = 0; i < l-1; i++) {
    /* code */


    //printf("i%% 6 =%d\n", i%6);
    //printf("*(cuit+i)=%c\n", *(cuit+i));
    if (*(cuit+i)<'0' || *(cuit+i)>'9') {
      printf("Ingresaste algo que no es un numero\n");
      return (-2);
    }
    //printf("acumulacion[%d]:%d\n",i, acumulacion);
    //acumulacion+=((*(cuit+strlen(cuit)-i)-'0')*secuencia[i%6]);
    acumulacion+=((*(cuit+i)-'0')*secuencia[i]);
    j++;
  }
  //printf("El resultado de la acumulacion vale:%d\n", acumulacion);
  resultado=11-(acumulacion%11);
  if (resultado==11) {
    resultado=0;
  }else{
    if (resultado==10) {
      resultado=9;
    }
  }if (resultado+'0'==*(cuit +l-1)) {
    return resultado;
  }
  return (-3);
}

int main() {
  char cuit[]="20123456780";
//  char digitoverificador="0";
  int a=0;
  a=cuitValida(cuit);
  printf("El resultado de cuitValida es:%d\n", a);
  return 0;
}
