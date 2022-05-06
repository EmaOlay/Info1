int hexaCmp(char *a, char *b){
  int i=0,j=0;
  int comparacion=-256;
  //reviso la cantidad de digitos en a y si son validos
  while (*(a+i)!='\0' ) {
    if (!(*(a+i)>='0' && *(a+i)<='9') && !(*(a+i)>='A' && *(a+i)<='F')) {
      printf("El primer hexa contiene un simbolo que no va\n");
      return (-2);

    }
    i++;
  }
  //reviso la cantidad de digitos en b y si son validos
  while (*(b+j)!='\0' ) {
    if (!(*(b+j)>='0' && *(b+j)<='9') && !(*(b+j)>='A' && *(b+j)<='F')) {
      printf("El segundo hexa contiene un simbolo que no va\n");
      return (-2);
    }
    j++;
  }
  comparacion=strcmp(a,b);
  if (comparacion==0) {//check por igual
    return 0;
  }
  if (comparacion>0) {//check por a mayor a b
    return 1;
  }
  if (comparacion<0) {//check por a menor a b
    return -1;
  }
  if (comparacion==-256) {
    printf("Algo fallo\n");
  }
  if (i!=3 || j!=3) {//reviso que tenga 4 digitos exactos
    printf("Alguno de los 2 no tiene 4 digitos\n");
    return (-3);
  }
  return comparacion;
}

int decodificadorMorse (char *texto, char *morse){
  int i=0;
  char aux;
  char *tabla[]={".- ",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--..",
};
*(morse+0)='\0';

  while (*(texto+i)!='\0') {

    aux=tolower(*(texto+i));
    printf("%c\n", *(texto+i));
    if ((aux>='a' || aux<='z') || aux==' ' ) {
      if (aux==' ') {
        strcat(morse," ");
      }else{
      strcat(morse,tabla[aux-'a']);
      }
    }else{

      printf("No es letra min\n");
      return (-1);
    }
    i++;
  }
  return 0;
}
int codificadorMorse(char *morse, char *texto){
int i=0;
int h=0;
int x=0;
int flag_coincidencia=0;
char aux[5];
char *tabla[]={".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--..",
};

while (*(morse+i)!='\0') {
  aux[h]=*(morse+i);
  h++;
  if (*(morse+i)==' ') {

    aux[h-1]='\0';
    printf("%s\n",aux );
    for (int j=0; j < sizeof(tabla)/sizeof(tabla[0]); j++) {
      flag_coincidencia=strcmp(aux,tabla[j]);
      if (flag_coincidencia==0) {
        printf("Entre\n");
        *(texto+x)=j+'a';
        x++;
        break;
      }

    }
    h=0;
  }
  i++;
}
*(texto+x)='\0';
return 0;
}
