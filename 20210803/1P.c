/*Parte teorica:
1) La respuesta correcta parece ser la D pero ni idea no creo que sea importante
2)Verdaderas:
              B

              D

*/

#include "funciones.c"

int main() {
  int vector[]={157192,160311,1144192,1143944,155960};//fruta
  int dataCant=sizeof(vector)/sizeof(*vector);
  /*printf("%d\n", sizeof(vector)/sizeof(*vector));
  printf("Afuera:\n");
  for (int i = 0; i < dataCant; i++) {
    showbits(vector[i]);
  }
  */
    convertir_a_string(vector,dataCant);
    printf("\n");
  //convertir_a_string(vector,dataCant);
  return 0;
}
