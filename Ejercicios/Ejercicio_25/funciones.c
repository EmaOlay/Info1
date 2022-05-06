#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int x, int y){
  if (y==0) {
    return(1);
  }else{
    //sigo haciendo x*x y le resto 1 a y
    return(x*potencia(x,y-1));
  }
}

int fibonacci(int n){
   //trato de fabricar esta secuencia:
   //{1,1,2,3,5,8,13,21,34,55,89,144...}
   if (n==0) {
     return(0);
   }
   if (n==1) {
     return(1);
   }
   if (n==2) {
     return(1);
   }else{
     return(fibonacci(n-1)+fibonacci(n-2));
   }
 }

void pasaje(int n,int * ptr){
  if (n>=1) {
    *(ptr)=n%2;
    if (n/2==0) {
      return;
    }
    pasaje(n/2,ptr+1);
  }
}
