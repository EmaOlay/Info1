#include <stdio.h>
#include <math.h>

int main()
{
    //declaro variables float
    float a, frac;
    double entero;
    printf("Ingrese un numero:\n" );
    scanf("%f",&a);
    frac = modf(a, &entero);
    printf("El numero ingresado es: %g\n",a);//con %g recorta al ultimo numero
    printf("La parte entera es: %g\n",entero);
    printf("La parte decimal es: %g\n",frac);
    return (0);
}
