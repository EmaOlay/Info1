#include <stdio.h>
#include <string.h>

int validarPassword(char *dataPtr){
  char vector[]="~!@#$%^&*_-+='|\\(){}\[]:;\"'<>,.?/";
  int i=0, flag_mayus=0, flag_minus=0, flag_simbolo=0,flag_num=0;
  if (strlen(dataPtr)<8) {
    return (-1);
  }
  while (*(dataPtr+i)!='\0') {
    //check espacios
    if (*(dataPtr+i)==' ') {
      return (-2);
    }
    //mayus check
    if (*(dataPtr+i)>='A' && *(dataPtr+i)<='Z') {
      flag_mayus=1;
    }
    //check flag_minus
    if (*(dataPtr+i)>='a' && *(dataPtr+i)<='z') {
      flag_minus=1;
    }
    //check numeros
    if (*(dataPtr+i)>='0' && *(dataPtr+i)<='9') {
      flag_num=1;
    }
    //check simbolos 1
    for (int j = 0; j < strlen(vector); j++) {
      if (*(dataPtr+i)==vector[j]) {
        flag_simbolo=1;
      }
    }

    i++;
  }
  if (flag_num==1 && flag_mayus==1 && flag_minus==1 && flag_simbolo==1) {
    return 1;
  }
  if (flag_mayus==0) {
    return (-3);
  }
  if (flag_minus==0) {
    return (-3);
  }
  if (flag_simbolo==0) {
    return (-4);
  }
  if (flag_num==0) {
    return (-5);
  }
  //Si llegaste hasta aca la re bardeaste
return 0;
}

int main() {
  //char password[]="PassValida123!";
  //char password[]="PassNo";
  int a;
  char password[20];
  printf("Ingrese una pass\n");
  scanf("%19[^\n]s", password);
  a=validarPassword(password);
  switch (a) {
    case 1:
    printf("La pass es valida\n");
    break;
    case -1:
    printf("La pass es muy corta\n");
    break;
    case -2:
    printf("La pass tiene espacios\n");
    break;
    case -3:
    printf("La pass carece de una mayuscula o minuscula\n");
    break;
    case -4:
    printf("La pass carece de un simbolo valido\n");
    break;
    case -5:
    printf("La pass carece de un numero\n");
    break;
  }
  return 0;
}
