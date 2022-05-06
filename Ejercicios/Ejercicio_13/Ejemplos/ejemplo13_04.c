#include <stdio.h>

#define CANT ((int) 10)

char pasaAminusculas (char a)
{
  char r;
  if ((a>='A')&&(a<='Z')) {
    r=(a-'A')+'a';
  } else {
    r=a;
  }
  return (r);
}

int main() {
  char c,r;
  printf("Ingrese una letra\r\n");
  scanf("%c", &c);

  r=pasaAminusculas(c);
  printf("Resultado = %c\r\n", r);
  return 0;
}
