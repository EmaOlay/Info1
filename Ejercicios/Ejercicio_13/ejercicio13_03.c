#include <stdio.h>

#define  MAYUS ((int) 0)
#define  MINUS ((int) 1)
#define  NUMER ((int) 2)
#define  OTRO  ((int) 3)

int filtroASCII (char caracter){
  int respuesta=OTRO;
  if ((caracter>='A')&&(caracter<='Z')) {
    respuesta=MAYUS;
  }
  if ((caracter>='a')&&(caracter<='z')) {
    respuesta=MINUS;
  }
  if ((caracter>='0')&&(caracter<='9')) {
    respuesta=NUMER;
  }
  return respuesta;
}

int main() {
  char c;
  int estado;

  //Pido el caracter
  printf("Ingrese algo...\n");
  scanf("%c", &c);
  estado=filtroASCII(c);
  switch (estado) {
    case MAYUS:
    printf("El caracter es una mayuscula\n");
    break;
    case MINUS:
    printf("El caracter es una minuscula\n");
    break;
    case NUMER:
    printf("El caracter es un numero\n");
    break;
    case OTRO:
    printf("El caracter es otra cosa\n");
    break;
  }

  return 0;
}
