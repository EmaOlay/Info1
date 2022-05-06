int tamanioPalabra(char *str, char *corta, char *larga){
  int i=0,k=0,j=0,cont_largo=0,cont_corta=20,cont_palabra=0;//corta empieza en 20 para forzar el primer ingreso
  //j cuenta palabras
  //k el largo de las palabras
  //i le pega hasta el fondo
  char aux_palabra[50];
  while (*(str+i)!='\0') {
    aux_palabra[k]=*(str+i);
    //printf("k=%d\n", k);
    //printf("j=%d\n", j);
    k++;
    if (*(str+i)==';') {
      //en lugar del ';' le pongo '\0'
      aux_palabra[k-1]='\0';
      j++;
      //printf("aux_palabra= %s\n", aux_palabra);

      cont_palabra=k;
      if (cont_palabra>cont_largo) {//es mas larga que el ultimo registrado
        cont_largo=cont_palabra;
        //asigno el contenido del puntero con el contenido de mi string aux
        strcpy(larga,aux_palabra);
      }

      if (cont_palabra<cont_corta) {//es mas corta que el ultimo registrado
        cont_corta=cont_palabra;
        //asigno el contenido del puntero con el contenido de mi string
        strcpy(corta,aux_palabra);

      }
      k=0;
    }

    i++;
  }
  return j;
}



float operacionesBasicas (char*p){
  int i=0, pos_ope=0;
  float a,b;
  //saco los espacios tambien podria sacar otras cosas pero se los dejo a uds
  while (*(p+i)!='\0') {
    if (*(p+i)==' ') {
      strcpy(p+i,p+i+1);
    }
    i++;
  }
  //aseguro un string bien formado, no deberia hacer falta pero mehhh...
  *(p+i)='\0';
    //levanto a
    a=atof(p);
  //recorro buscando la operacion no arranco en 0 porque podria ser el signo de a
    for (int i = 1; i < strlen(p); i++){
      if (*(p+i)=='+' || *(p+i)=='-' || *(p+i)=='*' || *(p+i)=='/'){
        pos_ope=i;
        //ya encontre la ope no necesito seguir
        break;
      }
    }
  if (pos_ope==0) {//recorri todo y no encontre operacion valida
    printf("No hay operacion valida\n");
    return -3000;
  }
  //lo que venga despues de pos_ope es el numero b
  b=atof(p+pos_ope+1);
  printf("%g%c%g\n",a,*(p+pos_ope),b );
  //resuelvo
  if (*(p+pos_ope)=='+') {
    return a+b;
  }
  if (*(p+pos_ope)=='-') {
    return a-b;
  }
  if (*(p+pos_ope)=='*') {
    return a*b;
  }
  if (*(p+pos_ope)=='/') {
    return a/b;
  }
//codigo de error podria poner otra cosa pero mehhh...
  return -3000;
}
