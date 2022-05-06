#include <stdio.h>
#include <math.h>

float calcularPromedio(char *dataPtr){
  int i=0;
  float acum=0,res=0;
  while (*(dataPtr+i)!='\0') {
    //printf("*(dataPtr+%d)=%c\n",i,*(dataPtr+i) );
    if ((*(dataPtr+i+1)==' ')&&(*(dataPtr+i)>='0' && *(dataPtr+i)<='9')) {
      acum+= (*(dataPtr+i)-'0');
    }else{
      return NAN;
    }
//logica para la basura
    i+=2;
  }
  //printf("acum vale:%f\n", acum);
  //printf("i vale:%d\n", i);
  res=acum/(i/2);
  return res;
}

int main() {
  //char notas[]="0 1 2 3 4 5 6 7 8 9";
  char notas[20];
  float respuesta;
  printf("Ingrese un string con notas\n");
  scanf("%20[^\n]",notas );//%149[^\n]
  //fgets(notas,20,stdin);
  printf("notas :%s\n", notas);
  respuesta=calcularPromedio(notas);
  printf("El promedio de las notas es:%g\n", respuesta);

  return 0;
}
