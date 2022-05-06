#include <stdio.h>
#include <stdlib.h>

struct data {
  int a;
  char v[64];
};

int func (void) {
  printf ("Hola\r\n");
  return (0);
}

int main() {
  int *p=NULL;
  //Agrego algo por mi cuenta para probar
  p=(int *)malloc(sizeof(*p));
  //Tremendo segmentation fault si no lo inicializo ni idea why
  *p=64;
  printf("Print Teorica 1\n");
  //Imprime el equivalente a 64 en la tabla ascii osea @
  printf("*p = %c\n", *p);

  printf("Print Teorica 2\n");
  //declara matriz de 2x2
  int m[2][2] = {{1,2}, {3, 4}};

  int i, j;
  //primer vuelta imprime el componente 00 osea 1
  //segunda vuelta imprime el 10 osea el 3
  //Es sencialla mente pensar que imprime filas X columnas
    for (i = 0; i < 2; i++)
      for (j = 0; j < 2; j++)
      printf("%d\r\n", m[j][i]);

  printf("Print Teorica 3\n");
  //Porque pelotas hacer un char *? No te va a tirar warning?
  //Se que todos los punteros son de 8bytes pero igua...
  char *ptr;
  ptr = (char *)malloc (sizeof (struct data));
  //Me podria tirar la sumas de sizeof(int)+ sizeof(char *64)
  //O algun acomodo raro que suele pasar con las structs...
  //Como da 1? WTF? por lo menos 4 no?
  printf ("sizeof (*ptr) = %ld\r\n",sizeof (*ptr));

  printf("Print Teorica 4\n");
  //Hace el sizeof de lo que devuelve la funcion
  printf("sizeof(func()) = %ld\r\n", sizeof(func()));

  return 0;
}
