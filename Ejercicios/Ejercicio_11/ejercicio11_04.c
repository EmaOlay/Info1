#include <stdio.h>

int main() {
  //declaro variables
  int i=0;

  do {
    printf("La variable i vale: %d\n", i);
    i+=1;// Porque puedo, equivale a i++;
  } while(i<10);
  return 0;
}
