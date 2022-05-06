#include <stdio.h>

int validaString(char *dataPtr){
  int flag_numero=0,flag_letra=0,i=0;
  while(*(dataPtr+i)!='\0'){
    if (*(dataPtr+i)>='0' && *(dataPtr+i)<='9') {
      flag_numero=1;
    }
    if (*(dataPtr+i)>='a' && *(dataPtr+i)<='z') {
      flag_letra=1;
    }
    if (*(dataPtr+i)>='A' && *(dataPtr+i)<='Z') {
      flag_letra=1;
    }
    printf("*(dataPtr+%d)=%c\n",i,*(dataPtr+i) );
    i++;
  }
  if (flag_letra==1 && flag_numero==0) {
    return 1;
  }
  if (flag_letra==0 && flag_numero==1) {
    return 2;
  }
  return 0;
}

int main() {
  char string[50];//Asumo que no van a necesitar mas de 50
  int res;
  printf("Ingrese algo al string\n");
  scanf("%s", string);
  res=validaString(string);
  printf("El resultado de validaString es:%d\n", res);
  return 0;
}
