#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return dataPtr_aux;
}
int main() {

  char string[]="El perro pepe es un crack.";
  char string_buscar[]="perro";
  char string_nuevo[]="colectivo";
  int cant=0;

  /*
  char string[100];
  char string_buscar[15];
  char string_nuevo[15];
  char fin_basura;
  int cant=0;
  //pido string
  printf("Ingrese un string\n");
  scanf("%99[^\n]s", string);
  scanf("%c", &fin_basura);
  //pido string a cambiar
  printf("Ingrese un string a buscar\n");
  scanf("%15[^\n]s", string_buscar);
  scanf("%c", &fin_basura);
  //pido string nuevo
  printf("Ingrese un string para cambiar\n");
  scanf("%15[^\n]s", string_nuevo);
  scanf("%c", &fin_basura);
  */
  printf("%s\n",string );
  printf("%s\n", reemplazarPalabra(string,string_buscar,string_nuevo,&cant));
  printf("La cantidad de palabras reemplazadas fue:%d\n", cant);
  return 0;
}
