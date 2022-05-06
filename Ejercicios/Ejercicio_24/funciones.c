#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void char2bin(unsigned char data, char *binPtr){
int i;
  int sizeBit= sizeof(data)*8;

  memset(binPtr,'\0',sizeof(*binPtr));
  for (i = 0; i < sizeBit; i++) {
    if ((data %2)==0) {
      *(binPtr + sizeBit -1 -i) = '0';
    }else{
      *(binPtr + sizeBit -1 -i) = '1';
    }
    data=data>>1;
  }
  *(binPtr + i)= '\0';
}

int leerBit(int palabra, int bit){
  if (bit>(sizeof(palabra)*8 +1) || bit<0) {
    printf("Pediste un bit por fuera del dato:%d\n",bit);
    printf("El maximo es: %ld\n",sizeof(palabra)*8 );
    return -1;
  }
  palabra=palabra>>bit;
  return (palabra&1);
}

int negarBit(int palabra, int bit){
  if (bit>(sizeof(palabra)*8 +1) || bit<0) {
    printf("Pediste un bit por fuera del dato:%d\n",bit);
    printf("El maximo es: %ld\n",sizeof(palabra)*8 );
    return -1;
  }
  palabra=palabra^(0x01<<bit);
  return(palabra);
}

int escribirBit(int palabra, int bit, int datoBit){
  if (bit>(sizeof(palabra)*8 +1) || bit<0) {
    printf("Pediste un bit por fuera del dato:%d\n",bit);
    printf("El maximo es: %ld\n",sizeof(palabra)*8 );
    return -1;
  }
  if (datoBit==1) {
    palabra=palabra|(0x01<<bit);
  }else{
    palabra=palabra&(~(0x01<<bit));
  }
  return(palabra);
}

int escribirNibble(int palabra, int nibble, int datoBit){
  if (nibble>((sizeof(palabra)*8)/4 +1) || nibble<0) {
    printf("Pediste un bit por fuera del dato:%d\n",nibble);
    printf("El maximo es: %ld\n",sizeof(palabra)*8 );
    return -1;
  }

  if (datoBit==1) {
    palabra=palabra|(<<nibble*4);
  }else{
    palabra=palabra&(~(0x04<<nibble));
  }
  return(palabra);
}
