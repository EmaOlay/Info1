#include <stdio.h>
#define  CANT ((int) 5)

/*
int esNumero (int *dataPtr){
  int i=0;
  int flag_num=0;
  while (*(dataPtr+i)>=0 && *(dataPtr+i)<=9) {
    printf("*(dataPtr+%d) = %d\n",i, *(dataPtr+i));
    if (*(dataPtr+i)>=0 && *(dataPtr+i)<=9) {
      flag_num=1;
    }else{
      return 0;
    }
    i++;
  }

  return flag_num;
}
*/
int esNumero (char *dataPtr){
  int i=0;
  int flag_num=0;
  while (*(dataPtr+i)!='\0') {
    printf("*(dataPtr+%d) = %c\n",i, *(dataPtr+i));
    if (*(dataPtr+i)>='0' && *(dataPtr+i)<='9') {
      flag_num=1;
    }else{
      return 0;
    }
    i++;
  }

  return flag_num;
}

int main() {
  int a;
  /*int array[CANT];

  for (int i = 0; i < CANT; i++) {
    printf("Ingrese un string\n");
    scanf("%d", &array[i]);
  }
  */

  char array[CANT];
  printf("Ingrese un string\n");
  scanf("%s", array);
  
  a=esNumero(array);
  printf("El resultado de esNumero fue: %d\n", a);
  return 0;
}
