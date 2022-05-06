#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE_CANT ((int)16) //!< Cantidad maxima de elementos del nombre.
#define CANT ((int) 3)
struct persona {
  char *nombre;
  int edad;
  char sexo;
};
int main (void){
struct persona estudiante[CANT];
char nombre[NOMBRE_CANT];
//-- Inicializo la estructura --
for (int i = 0; i < CANT; i++) {
  printf ("Ingrese nombre:\r\n"); scanf ("%s", &nombre[0]);
  estudiante[i].nombre = (char *)malloc (strlen (nombre) + 1);
  if (estudiante[i].nombre == NULL) {
    return (-1);
  } else {
    strcpy (estudiante[i].nombre, nombre);
  }
  scanf ("%c", &estudiante[i].sexo);
  printf ("Ingrese sexo:\r\n");
  scanf ("%c", &estudiante[i].sexo);
  printf ("Ingrese edad:\r\n");
  scanf ("%d", &estudiante[i].edad);
}

//-- Imprimo la estructura --
for (int i = 0; i < CANT; i++) {
  printf ("Nombre: %s\r\n", estudiante[i].nombre);
  printf ("Edad: %d\r\n", estudiante[i].edad);
  printf ("Sexo: %c\r\n", estudiante[i].sexo);
}
for (int i = 0; i < CANT; i++) {
  free(estudiante[i].nombre);
}
return (0);
}
