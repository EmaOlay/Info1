#include <stdio.h>
#define CANT ((int)32)
int main (void)
{
char v[CANT];
char vocales[] = {'a','e','i','o','u','A','E','I','O','U'};
int vocalesCont = 0;
int i, j;
  //-- Ingreso palabra --
  printf("Ingrese palabra\r\n");
  scanf("%s", &v[0]);
  //-- Cuento las vocales --
  i = 0;
  while (v[i] != '\0') {
    for (j = 0; j < sizeof (vocales); j++) {
      if (v[i] == vocales[j]) {
        vocalesCont++;
      }
    }
    i++;
  }
printf("La cantidad de vocales es: %d\r\n", vocalesCont);
return (0);
}
