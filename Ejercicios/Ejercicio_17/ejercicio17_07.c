#include <stdio.h>

int detectorPalindromo(char *palabraPtr){
  int palabra_aux[20],i=0;
  while (*(palabraPtr+i)!='\0') {
    palabra_aux[i]=*(palabraPtr+i);
    i++;
  }
  
  if (i<2) {
    return (-2);
  }

  for (int j = 0; j < i; j++) {
    if (*(palabraPtr+j)!=(palabra_aux[i-j-1])) {
      return (-1);
    }
  }
  return 0;
}

int main() {
  char palabra[20];
  int a;
  printf("Ingrese una palabra\n");
  scanf("%s", palabra);
  a=detectorPalindromo(palabra);
  if (a==0) {
    printf("Es palindromo\n");
  }
  if (a==-1) {
    printf("No es palin\n");
  }
  if (a==-2) {
    printf("La palabra es muy corta\n");
  }

  return 0;
}
