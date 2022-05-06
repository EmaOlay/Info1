#include <stdio.h>
#include <math.h>


int hexaToDec(char *dataPtr){
  int i=0;
  int aux=0;
  while (*(dataPtr+i)!='\0') {
    //printf("*(dataPtr+i) = %c\n", *(dataPtr+i));
    int precedencia= pow(16,3-i);
    //printf("precedencia sub %d es %d\n",i, precedencia);
    if (*(dataPtr+i)>='0' && *(dataPtr+i)<='9') {
      aux+=((*(dataPtr+i)-'0') * precedencia);//*(dataPtr+i) ta en ascii...
//printf("iteracion %d hago %c * %d\r\n",i,*(dataPtr+i),precedencia );

    }
    if (*(dataPtr+i)>='A' && *(dataPtr+i)<='F') {

      aux+=((*(dataPtr+i)-'A'+10) * precedencia);//*(dataPtr+i) ta en ascii...
//printf("iteracion %d hago %c * %d\r\n",i,*(dataPtr+i),precedencia );

    }
    if (!(*(dataPtr+i)>='0' && *(dataPtr+i)<='9') && !(*(dataPtr+i)>='A' && *(dataPtr+i)<='F')) {
      return (-1);
    }
    i++;
  }
  if (i!=4) {
  return (-2);
  }
  return aux;
}

int main() {
  int a=0;
  char Hexa_Dato[6];//6 para probar el error por mayor
  printf("Ingrese un Hexa de 4 Digitos\n");
  scanf("%s", Hexa_Dato);
  a=hexaToDec(Hexa_Dato);
  if (a==-1) {
    printf("Hay un simbolo que no corresponde a un Hexa\n");
    return 0;
  }
  if (a==-2) {
    printf("La cantidad de digitos es distinta de 4\n");
    return 0;
  }
  printf("El numero Hexa es:%s\n", Hexa_Dato);
  printf("El numero en Dec es:%d\n", a);
  return 0;
}
