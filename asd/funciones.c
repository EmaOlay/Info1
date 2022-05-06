/*Cuando uses memoria dinamica usa:
valgrind --leak-check=full ./ejemplo.out
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ES_MIN (*(string+j+1)>='a'&& *(string+j+1)<='z')
#define ES_MAYU (*(string+j+1)>='A'&& *(string+j+1)<='Z')
char separadores[]={'!','\"','?',',','.',';','\'',' ','\n'};
/*
ptr_aux=(int*)realloc(sizeof(int)*cant_separadores);
if (ptr_aux==NULL) {
  printf("Error pidiendo memoria\n");
  return(-1);
}else{
  *resultado=ptr_aux;
}
*/

void reordenar_int(int n, int* x)/* reordenar la lista de números */
{
  int i,elem, temp;

  for (elem = 0; elem < n - 1; ++elem)/* encontrar el menor del resto de los elementos*/
    for (i = elem + 1; i < n; ++i)
      if (x[i] > x[elem]) {//con < es de menor a mayor
                           //con > es de mayor a menor
      /* intercambiar los dos elementos */
      temp = x [elem];
      x[elem] = x[i];
      x[i] = temp;
      }
  return;
}
int contarPalabras(char* string){
  int j=0;
  int cant=0;
  while (*(string+j)!='\0') {
    for (int i = 0; i < strlen(separadores); i++) {
      if (string[j] == separadores[i] && (string[j+1] != ' ' || string[j+1] == '\0')){
        cant++;
      }
    }

    j++;
  }
  return cant;
}
int contarPalabra(char* str, char* palabracontar){
  int j=0;
  int cant=0;
  while (*(str+j)!='\0') {
      // comparo
      if (strstr(str+j, palabracontar) == str+j) {
          cant++;
          j+= strlen(palabracontar);
      }
      else{
        j++;
      }
  }
  if (cant>0) {
    return cant;
  }
  return -1;
}
//tambien sirve para quitar cosas pero es un quilombo si queres quitar varias distintas
char* reemplazarPalabra(char *dataPtr, char *palabraBuscar, char *palabraNueva,int* cantCambios){
    int i,j=0, cont = 0;
    int Buscarlen = strlen(palabraBuscar);
    int Nuevalen = strlen(palabraNueva);
    char* dataPtr_aux=NULL;

    //Cuento la cantidad de veces que aparece la palabraBuscar
    //strstr no le importa los tamanios pero solo informa la primera vez
    for (i = 0; *(dataPtr + i) != '\0'; i++) {
      //strstr te devuelve la direccion en la que encontro la palabra
      //Entonces si coincide con la direccion en la que estoy +1
        if (strstr((dataPtr + i), palabraBuscar) == (dataPtr + i)) {
            cont++;
            //Me adelanto Buscarlen para evitar falsos positivos
            i += Buscarlen - 1;
        }
    }
    *(cantCambios)=cont;
    //i es el largo de mi string origen a eso le agrego o quito cont veces
    //la diferencia entre la palabraNueva y palabraBuscar + 1 por el \0
    //Esto es quivalente a malloc lo uso porque si el dataPtr original fuese generado con malloc podria meterlo aca
    dataPtr_aux = (char*)realloc (dataPtr_aux,i + cont * (Nuevalen - Buscarlen) + 1);
    if (dataPtr_aux == NULL) {
      printf("Error pidiendo memoria\n");
      return (NULL);
    }
    i = 0;
    while (*(dataPtr+j)!='\0') {
        // comparo
        if (strstr(dataPtr+j, palabraBuscar) == dataPtr+j) {
            strcpy((dataPtr_aux+i), palabraNueva);
            //adelanto Nuevalen en i
            i += Nuevalen;
            //adelanto Buscarlen en copia
            j += Buscarlen;
        }
        else{
          *(dataPtr_aux + i++)=*(dataPtr + j++);
        }
    }

    dataPtr_aux[i] = '\0';
    //devuelvo el nuevo string con los cambios
    return dataPtr_aux;
}
void eliminarCaracter(char* dataPtr, char c){
  int len=strlen(dataPtr);
  for (int i = 0; i < len; i++) {
    if (*(dataPtr+i)==c) {
      for (int j = i; j < len; j++) {
        *(dataPtr+j)=*(dataPtr+j+1);
      }
      len--;
      i--;
    }
  }
}
