#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define  CANT ((int) 10)

int main(int argc, char const *argv[]) {
  int i;
  srand(time(NULL));
  for ( i = 0; i < CANT; i++) {
    printf("%d\n", rand());
  }
  return 0;
}
