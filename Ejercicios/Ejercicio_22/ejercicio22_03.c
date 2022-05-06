#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  // Stop, get some help use atoi
  if (argc>4) {
    printf("Argumentos de mas!\n");
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
      printf("*argv[%d]=%c\n", i,*argv[i]);
    }
    return(-1);
  }
  if (argc<4) {
    printf("Argumentos de menos!\n");
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
      printf("*argv[%d]=%c\n", i,*argv[i]);
    }
    return(-1);
  }
  int a,b;
  a=atoi(argv[1]);
  b=atoi(argv[3]);
  switch (*argv[2]) {
    case '+':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],a + b);
    break;
    case '-':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],a - b);
    break;
    case '*':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],a * b);
    break;
    case '/':
    printf("%s %c %s=%g\n",argv[1],*argv[2],argv[3],((float)a / b));
    break;
    default:
    printf("Operacion no valida\n");
    break;
  }
  /*
  switch (*argv[2]) {
    case '+':
    if ((*argv[1]>='0'&& *argv[1]<='9')&&(*argv[3]>='0'&& *argv[3]<='9')) {
      printf("%c %c %c=%c\n",*argv[1],*argv[2],*argv[3],*argv[1]+ *argv[3]);
    }else{
      printf("No ingresaste numeros validos\n");
    }
    break;
    case '-':
    if ((*argv[1]>='0'&& *argv[1]<='9')&&(*argv[3]>='0'&& *argv[3]<='9')) {
      printf("%c %c %c=%d\n",*argv[1],*argv[2],*argv[3],(*argv[1] - '0') - (*argv[3]-'0'));
    }else{
      printf("No ingresaste numeros validos\n");
    }
    break;
    case '*':
    if ((*argv[1]>='0'&& *argv[1]<='9')&&(*argv[3]>='0'&& *argv[3]<='9')) {
      printf("%c %c %c=%d\n",*argv[1],*argv[2],*argv[3],(*argv[1]-'0')* (*argv[3]-'0'));
    }else{
      printf("No ingresaste numeros validos\n");
    }
    break;
    case '/':
    if ((*argv[1]>='0'&& *argv[1]<='9')&&(*argv[3]>='0'&& *argv[3]<='9')) {
      printf("%c %c %c=%d\n",*argv[1],*argv[2],*argv[3],(*argv[1]-'0')/ (*argv[3]-'0'));
    }else{
      printf("No ingresaste numeros validos\n");
    }
    break;
    default:
    printf("Operacion no valida\n");
    break;
  }
  */
  return 0;
}
