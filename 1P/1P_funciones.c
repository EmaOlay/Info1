/*Cuando uses memoria dinamica usa:
valgrind --leak-check=full ./ejemplo.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insertarInt(int *dataPtr,int dataCant,int n, int op){
  int res=0;
  if (op==1) {
    res=dataPtr[0];
    for (int i = 0; i < dataCant-1; i++) {
      dataPtr[i]=dataPtr[i+1];
    }
    *(dataPtr+dataCant-1)=n;

  }
  if (op==0) {
    res=dataPtr[dataCant-1];
    for (int i = dataCant; i > 0; i--) {
      dataPtr[i-1]=dataPtr[i-2];
    }
    dataPtr[0]=n;
  }
  return res;
}


char* reemplazarPalabra(char *dataPtr, char *palabraBuscar, char *palabraNueva){
    int i,j=0, cont = 0;
    int Buscarlen = strlen(palabraBuscar);
    int Nuevalen = strlen(palabraNueva);
    char* dataPtr_aux=NULL;
    //check que el dataPtr no este vacio
    if (strlen(dataPtr)==0) {
      printf("dataPtr vacio\n");
      return NULL;
    }
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

char* listaPalabra(char*str){
  int i=0,j=0,k=0;
  char matriz[100][100]={0};
  int cant_tot=0;
  int nuevo_tamanio=0;
  char* dataPtr_aux=NULL;
  //verifico el largo
  if (strlen(str)==0) {
    printf("dataPtr vacio\n");
    return NULL;
  }
  //separo palabras
  while(str[k]!='\0')
  {   //vuelvo el carretel jajaja
      j=0;
      while(str[k]!=';'&&str[k]!='\0')
      {
          matriz[i][j]=str[k];
          k++;
          j++;
      }
      matriz[i][j]='\0';
      i++;
      if(str[k]!='\0')
      {
          k++;
      }
  }
  //cantidad total de palabras encontradas
  cant_tot=i;

  //comparo adentro de la matriz y quito las que sean iguales
  for(i=0;i<cant_tot;i++)
  {
    for(j=i+1;j<cant_tot;)
     {
       if(strcmp(matriz[i],matriz[j])==0)
        {
           for(k=j;k<cant_tot;k++)
            {
              strcpy(matriz[k],matriz[k+1]);
            }
              cant_tot--;
         }
        else
         {
           j++;
         }
      }
   }
//agrego el ; a las palabras que quedaron
//no deberia necesitar agregar el \0 porque ya lo inicialice a 0
for(i=0;i<cant_tot;i++){
  matriz[i][strlen(matriz[i])]=';';
}
//calculo el nuevo tamanio
for(i=0;i<cant_tot;i++){
  nuevo_tamanio+=(strlen(matriz[i]));
//printf("%s",matriz[i]);
}
//printf("%d\n",nuevo_tamanio );
//pido memoria para el nuevo tamanio

dataPtr_aux = (char*)realloc (dataPtr_aux,nuevo_tamanio + 1);
if (dataPtr_aux == NULL) {
  printf("Error pidiendo memoria\n");
  return (NULL);
}
dataPtr_aux[0]='\0';
for(i=0;i<cant_tot;i++){
  strcat(dataPtr_aux,matriz[i]);
}
return dataPtr_aux;
}
