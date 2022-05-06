#include "1P_funciones.c"
/*
valgrind --leak-check=full ./1P_02.out
HAY que hacer tantos free como veces llames a la funcion
*/
int main() {

  char string_origen0[]="Spending time at national parks can be an exciting adventure, but this wasn't the type of excitement she was hoping to experience. As she contemplated the situation she found herself in, she knew she'd gotten herself in a little more than she bargained for. It wasn't often that she found herself in a tree staring down at a pack of wolves that were looking to make her their next meal.";
  char* string_destino0=NULL;
  char palabraBuscar0[]="parks";
  char palabraNueva0[]="parques";

  string_destino0=reemplazarPalabra(string_origen0, palabraBuscar0, palabraNueva0);
  printf("El string original es:\n%s\n",string_origen0 );
  printf("El string destino es:\n%s\n",string_destino0 );
  free(string_destino0);

  /*
  char string_origen1[]="";
  char* string_destino1=NULL;
  char palabraBuscar1[]="parks";
  char palabraNueva1[]="parques";

  string_destino1=reemplazarPalabra(string_origen1, palabraBuscar1, palabraNueva1);
  printf("El string original es:\n%s\n",string_origen1 );
  printf("El string destino es:\n%s\n",string_destino1 );
  */
  char string_origen2[]="Spending time at national parks can be an exciting adventure, but this wasn't the type of excitement she was hoping to experience. As she contemplated the situation she found herself in, she knew she'd gotten herself in a little more than she bargained for. It wasn't often that she found herself in a tree staring down at a pack of wolves that were looking to make her their next meal.";
  char* string_destino2=NULL;
  char palabraBuscar2[]="she";
  char palabraNueva2[]="ella";

  string_destino2=reemplazarPalabra(string_origen2, palabraBuscar2, palabraNueva2);
  printf("El string original es:\n%s\n",string_origen2 );
  printf("El string destino es:\n%s\n",string_destino2 );
  free(string_destino2);

  char string_origen3[]="Pruebo reemplazar por algo mas corto porque no lo hice antes";
  char* string_destino3=NULL;
  char palabraBuscar3[]="reemplazar";
  char palabraNueva3[]="exchange";

  string_destino3=reemplazarPalabra(string_origen3, palabraBuscar3, palabraNueva3);
  printf("El string original es:\n%s\n",string_origen3 );
  printf("El string destino es:\n%s\n",string_destino3 );
  free(string_destino3);
  return 0;
}
