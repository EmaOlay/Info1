#define NOT_MAYUS ((int) -1)
#define ENIE ((int) -2)
#define TAM_ALFABETO ((int) 25)
#define INDEX ((int) 26)
#define ERROR_D0 ((int) -3)
#define ERROR_D1 ((int) -4)
#define SIMBOLO_ENIE ((unsigned char)164)
#define SIMBOLO_ENIE2 ((unsigned char)165)

float pasaje_promedio(int viajes_realizados, float *tarifa, int *viajes, int tarifa_cant){
  //asumo que viajes realizados es el tamanio de viaje
  float resultado=0;
  float total_gastado=0;
  int viajes_aux=viajes_realizados;

    for (int i = tarifa_cant-1; i >= 0; i--) {
      if (viajes_aux>=viajes[i]) {
        total_gastado+=(tarifa[i]*(viajes_aux-viajes[i]));

        viajes_aux=viajes[i];
      }
    }
  printf("total_gastado=%g\n", total_gastado);
  printf("total viajado=%d\n", viajes_realizados);
  resultado=total_gastado/viajes_realizados;
  return resultado;
}

int rot_13 (char *dataPtr){
  //LA FUN SOLO ESTA DEFINIDA PARA MAYUS
  int i=0;
  int j=0;
  char tabla[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  while (*(dataPtr+i)!='\0') {
    /*if (strcmp((dataPtr+i),"Ñ")== 0) {
      return ENIE;
    }*/
    if ((*(dataPtr+i)<'A' || *(dataPtr+i)>'Z') && *(dataPtr+i)!=' ') {//no es mayus
      return NOT_MAYUS;
    }else{
      if (*(dataPtr+i)!=' ') {
        if (*(dataPtr+i)+13-'A' >TAM_ALFABETO) {//fuera de tabla

          *(dataPtr+i)=tabla[*(dataPtr+i)+13-INDEX-'A'];
        }else{
          *(dataPtr+i)=tabla[*(dataPtr+i)+13-'A'];
        }
        j++;
      }
    }
    i++;
  }
  return j;
}

int cbu_validar (char *dataPtr){
  int i=0;
  int R1=0;
  int R0=0;
  while (*(dataPtr+i)!='\0') {
    if (*(dataPtr+i)<'0'|| *(dataPtr+i)>'9') {
      return -2;
    }
    i++;
  }
  if (i!=22) {
    return -1;
  }
  int tabla0[]={9,7,1,9,7,1,3};
  for (int i = 0; i < 7; i++) {
    R0+=(*(dataPtr+i)-'0')*tabla0[i];
  }
  int tabla[]={9,7,1,3,9,7,1,3,9,7,1,3,9};
  for (int i = 0; i < 12; i++) {

    R1+= (*(dataPtr+8+i)-'0')*tabla[i];
  }
  if ((*(dataPtr+7)-'0')!=(10-(R0%10))) {
    return ERROR_D0;
  }
  if ((*(dataPtr+21)-'0')!=(10-(R1%10))) {
    return ERROR_D1;
  }
  return 0;
}
