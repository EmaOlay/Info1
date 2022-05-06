int invertir(char *dataPtr){
  //Metodo 1
  /*char *p;

  int j=0;

  p=(char *) malloc(sizeof(*dataPtr)*strlen(dataPtr));
  if (p==NULL) {
  printf("Error al pedir memoria\n");
  return(-1);
  }
  while (*(dataPtr +j)!='\0') {
    *(p+j)=*(dataPtr+(int)strlen(dataPtr)-j-1);
    j++;

  }
  strcpy(dataPtr,p);
  return(strlen(dataPtr));
  */
  //Metodo 2
  int i=0;
  char aux;
  while (i<strlen(dataPtr)/2) {
    aux= *(dataPtr+(int) strlen(dataPtr)-i-1);//guardo el ultimo
    *(dataPtr+strlen(dataPtr)-i-1)=*(dataPtr+i);//el ultimo lo piso con el primero
    *(dataPtr+i)=aux;//el primero lo piso con el ultimo
    i++;
  }
  return(strlen(dataPtr));
}

int mezclar(int *dataPtr0, int dataCant0, int *dataPtr1, int dataCant1, int *resultado){
  //me pasaron resultado asique debe ser lo suficientemente grande
  for (int i = 0; i < dataCant0; i++) {
    *(resultado+i)=*(dataPtr0+i);
    //printf("resultado[%d]=%d\n",i, *(resultado+i));
  }
  for (int i = 0; i < dataCant1; i++) {
    *(resultado+dataCant0+i)=*(dataPtr1+i);
    //printf("resultado[%d]=%d\n",dataCant0+i, *(resultado+dataCant0+i));
  }
  //ordeno con burbujeo
  for (int i = 0; i < (dataCant0+dataCant1) - 1; i++) {
    for (int j = i + 1; j < (dataCant0+dataCant1); j++) {
      if (*(resultado + i) > *(resultado + j)) {
        int aux = *(resultado + i);
        *(resultado + i) = *(resultado + j);
        *(resultado + j) = aux;
      }
    }
  }
return(dataCant0+dataCant1);
}

float asciiToFloat (char *dataPtr){
  /*No use atof jajajaj
  return strtod (dataPtr, (char **) NULL);*/

  int k=1;
  int i=0;
  int w=0;
  int j;
  int t=0;
  int flag_algo=0;
  int flag_menos=0;
  float resultado=0;
  //quito espacios

  while (*(dataPtr+t)!='\0'){
    //printf("%d\n %s\n %d\n",t, dataPtr,strlen(dataPtr));
    if (*(dataPtr+t)==' ') {
      memcpy(dataPtr+t,dataPtr+t+1,strlen(dataPtr)-t);
    }else{t++;}

  }
  //recorro posta
  i=0;
  while (*(dataPtr+i)!='\0') {
    if (isdigit(*(dataPtr+i)) || *(dataPtr+i)=='.' || *(dataPtr+i)=='-') {
      flag_algo=1;
      if (*(dataPtr+i)=='-') {
        flag_menos=1;
      }
      if (*(dataPtr+i)=='.') {
        j=i;
        //printf("J vale: %d\n", j);
      }
    }

  i++;
  }
  if (flag_algo==0) {
    printf("Basura\n");
    return(-1);
  }
  //creo el numero

  if (flag_menos==1) {
    w=j-1;
    //printf(" flag menos=%d\n",flag_menos );
  }else{w=j;}

  for (i = 0; i < w; i++) {
    resultado+= (*(dataPtr+j-i-1)-'0')*(powf(10,i));
    //printf("Iteracion %d de parte entera de resultado=%g\n",i,resultado );
  }
  for (i = j+1; i < strlen(dataPtr); i++) {

    resultado+= (*(dataPtr+i)-'0')*(powf(10,-k));
    //printf("Iteracion parte decimal: %g\n", (*(dataPtr+i)-'0')*(powf(10,-(k))));
    k++;
  }

  if (flag_menos==1) {
    return (-resultado);
  }
  return (resultado);
}
