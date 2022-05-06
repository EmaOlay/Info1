#include <stdio.h>

#define CANT ((int) 10)
/*
int main() {
  //Uso un vector no da declarar 10 varaibles para esto...
  int a=0, array[CANT];
  //pido datos
  while (a<CANT) {
    printf("Ingrese numero hasta llenar CANT\n");
    scanf("%d",(array+a) );

    //printf("%d\n",a ); //Compruebo el valor de a
    //printf("%d\n",array[a] );//Compruebo el valor de esa posicion del array
    a++;
  }
  //Burbujeo
  float temporal;

	for (int i = 0;i < CANT; i++){
		for (int j = 0; j< CANT-1; j++){
			if (array[j] < array[j+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = array[j];
			array[j] = array[j+1];
			array[j+1] = temporal;
			}
		}
	}
printf("El mayor elemento del array es: %d y el menor:%d\n",array[0],array[9] );

  return 0;
}
*/
int main() {
  //me aseguro que se pisen la primera vez que entran con esos valores
  int temp=0;
  int aux_min=2147483647;
  int aux_max=-2147483648;
  //printf("%d\n", sizeof(int));
  for (int i = 0; i < CANT; i++) {
    printf("Ingrese un numero\n");
    scanf("%d",&temp);
    if (temp>aux_max) {
      aux_max=temp;
    }
    if(temp<aux_min){
      aux_min=temp;
    }
  }
  printf("El minimo fue:%d, el maximo fue: %d\n",aux_min,aux_max );
  return 0;
}
