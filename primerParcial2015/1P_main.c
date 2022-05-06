#include <stdio.h>
int main (void)
{
int i;
char buffer[] = { 0x55, 0xAA, 0x22, 0x80 };
for (i = 0; i < sizeof (buffer); i++) {
printf ("%8x\t%d\r\n", buffer[i], buffer[i]);
}
puts ("");
return (0);
}
