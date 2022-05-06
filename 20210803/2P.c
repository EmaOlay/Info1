#include "funciones.c"


int main() {
  char vector[]="Nombre_fruta";
  char agregado[]="_decrypt";
  int cant_nueva=strlen(vector)+strlen(agregado)+1;
  //Asumo que el nuevo vector lo pidieron dinamicamente
  char* ptr_new_name=NULL;
  ptr_new_name=(char *) realloc(ptr_new_name,sizeof(*ptr_new_name)*cant_nueva);

  nvo_nombre(vector,ptr_new_name);
  printf("%s\n", ptr_new_name);
  return 0;
}
