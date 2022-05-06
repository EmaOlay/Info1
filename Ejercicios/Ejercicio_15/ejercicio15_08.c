#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX ((int) 10)

int convertirA_int(char *dataPtr){
  int res=0;
  int j=0;

    for (int i = strlen(dataPtr)-1; i >= 0; i--) {
      //warning del double??
      if (*(dataPtr+i)>='0' && *(dataPtr+i)<='9') {
      //printf("*(dataPtr +%d)=%d,(*(dataPtr+%d)-'0')*pow(10,%d)=%f\n",i,*(dataPtr +i)-'0',i,j,(*(dataPtr+i)-'0')*pow(10,j) );
      res+=(*(dataPtr+i)-'0')*pow(10,j);
      j++;
      }else{
      return -1;
      }
    }

  return (res);
}

int main() {
  char a[MAX];
  int var;
  printf("Ingrese un string:\n");
  scanf("%s", &a[0]);
  var=convertirA_int(&a[0]);
  //esto esta en int
  printf("El resultador de convertirA_int es:%d\n", var);
  return 0;
}
