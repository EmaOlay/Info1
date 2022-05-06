#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct gps_S {
char lat[7];
char ns;
char lon[8];
char wo;
int satCant;
};
//! Latitud de la posición
//! Norte - Sur
//! Longuitud de la posición
//!< Este - Oeste
//!< Cantidad de satélites, número entero positivo.
int main (void)
{
struct gps_S gps;
FILE *fd;
int i;
srandom (time(NULL));
fd = fopen ("gps.dat", "w");
for (i = 0; i < 100; i++) {
sprintf (gps.lat, "%2.3f", 34.598 + ((random () % 1000) / 1000.0));
gps.ns = random () % 2 ? 'S' : 'N';
sprintf (gps.lon, "%2.4f", 58.4194 + ((random () % 1000) / 1000.0));
gps.wo = random () % 2 ? 'W' : 'O';
gps.satCant = rand () % 25;
printf ("%s, %c, %s, %c, %d\r\n", gps.lat, gps.ns, gps.lon, gps.wo, gps.satCant);
fwrite (&gps, 1, sizeof (gps), fd);
}
fclose (fd);
return (0);
}
