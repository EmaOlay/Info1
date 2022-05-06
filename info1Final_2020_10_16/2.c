
#include "funciones.c"

int main() {
char codigo[]="5901234123453";
char codigo2[]="5901234123497";
char codigo3[]="5901234123450";
char * codigosVect[]={codigo,codigo2,codigo3};
int validos=0;
int invalidos=0;
verificarEan13 (codigosVect,3, &validos,&invalidos);
  printf("Validos=%d\nInvalidos=%d\n",validos,invalidos );
  return 0;
}
