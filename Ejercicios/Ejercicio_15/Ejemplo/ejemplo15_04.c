#include <stdio.h>
void suma (int *a, int *b, int *r)
{
*r = *a + *b;
return;
}
int main (void)
{
int x, y, r;
//-- Ingreso de los dos numeros a sumar --
printf ("Ingrese numero\r\n");
scanf ("%d", &x);
printf ("Ingrese numero\r\n");
scanf ("%d", &y);
suma (&x, &y, &r);
printf ("El resultado %d\r\n", r);
return (0);
}
