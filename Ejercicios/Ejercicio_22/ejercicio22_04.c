#include <stdio.h>
#include <stdlib.h>

#define SUMA ((int) 0)
#define RESTA ((int) 1)
#define DIVISION ((int) 2)
#define MULTI ((int) 3)

int suma(int a, int b){
  return(a + b);
}
int resta(int a, int b){
  return(a - b);
}
int divi(int a, int b){
  return((float)a / b);
}
int multi(int a, int b){
  return(a * b);
}
int main(int argc, char const *argv[]) {
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
  int (*func[4]) (int,int);
  func[SUMA]=suma;
  func[RESTA]=resta;
  func[DIVISION]=divi;
  func[MULTI]=multi;
  switch (*argv[2]) {
    case '+':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],func[SUMA](a,b));
    break;
    case '-':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],func[RESTA](a,b));
    break;
    case '*':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],func[MULTI](a,b));
    break;
    case '/':
    printf("%s %c %s=%d\n",argv[1],*argv[2],argv[3],func[DIVISION](a,b));
    break;
    default:
    printf("Operacion no valida\n");
    break;
  }
  return 0;
}
