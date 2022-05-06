#include <stdio.h>
#include <string.h>
#define NOMBRE_CANT ((int) 16)

struct persona {
  char nombre[NOMBRE_CANT];
  int edad;
  char sexo;
};

int main(){
  struct persona estudiante;
  //-- Inicializo la estructura --
  strcpy (&estudiante.nombre[0], "Juan");
  estudiante.edad = 18;
  estudiante.sexo = 'M';
  //-- Imprimo la estructura --
  printf ("Nombre: %s\r\n", estudiante.nombre);
  printf ("Edad: %d\r\n", estudiante.edad);
  printf ("Sexo: %c\r\n", estudiante.sexo);
  return (0);

}
