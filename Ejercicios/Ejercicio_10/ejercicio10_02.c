#include <stdio.h>
#include <math.h>
int main() {
  double x,y;

  //ingreso de datos
  printf("Ingrese el valor x:\n");
  scanf("%lf",&x);
  printf("Ingrese el valor y:\n");
  scanf("%lf",&y);

  //Tomo decisiones
  if ((x==0)&&(y==0)) {
    printf("Las coordenadas ingresadas son el origen\n");
  } else {
    if (x>0) {
      if (y>0) {
        printf("Las coordenadas estan en el primer cuadrante\n");
      } else {
        printf("Las coordenadas estan en el cuarto cuadrante\n");

      }
    } else {
      if (y>0) {
        printf("Las coordenadas estan en el segundo cuadrante\n");
      } else {
        printf("Las coordenadas estan en el tercer cuadrante\n");

      }
    }
  }
  printf("Y la distancia al origen es:%g\n",sqrt(pow(x,2)+pow(y,2)) );
  return 0;
}
