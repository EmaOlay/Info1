#include <stdio.h>


#define FILS ((int)4)
#define COLS ((int)4)

int main(int argc, char const *argv[]) {
  int m[FILS][COLS]={{0,1,2,3},
                    {4,5,6,7},
                    {8,9,10,11},
                    {12,13,14,15}

  };

  int* p=m;
  int* pp=&m[1][0];
  for (int i = 0; i < 16; i++) {
    printf("%d\n",*(p+i) );
  }
  printf("%x\n",p );
  printf("%x\n",pp );
  return 0;
}
