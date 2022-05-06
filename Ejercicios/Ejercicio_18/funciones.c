struct persona {
  char *nombre;
  int edad;
  char sexo;
};
struct finales {
  char materia[16];
  int nota;
};
struct estudiante {
  char nombre[16];
  int cantFinales;
  struct finales *final;
};

struct persona* ingreso_persona (int dataCant){
  char nombre[16];
  struct persona* ptr_a_devolver;
  //--Pido memoria para las estructs--
  ptr_a_devolver = (struct persona*)malloc (sizeof(struct persona)*dataCant);
  if (ptr_a_devolver == NULL) {
    printf("Error pidiendo memoria para las estructuras\n");
    return (NULL);
  }
  //-- Inicializo la estructura --
  for (int i = 0; i < dataCant; i++) {
    printf ("Ingrese nombre:\r\n");
    scanf ("%s", &nombre[0]);
    (ptr_a_devolver +i)->nombre = (char *)malloc (strlen (nombre) + 1);
    if ((ptr_a_devolver +i)->nombre == NULL) {
      printf("Error pidiendo memoria para el nombre\n");
      return (NULL);
    } else {
      strcpy ((ptr_a_devolver +i)->nombre, nombre);
    }
    scanf ("%c", &(ptr_a_devolver +i)->sexo);
    printf ("Ingrese sexo:\r\n");
    scanf ("%c", &(ptr_a_devolver +i)->sexo);
    printf ("Ingrese edad:\r\n");
    scanf ("%d", &(ptr_a_devolver +i)->edad);
  }
return(ptr_a_devolver);
}

void imprimir(struct persona* p, int dataCant){
  for (int i = 0; i < dataCant; i++) {
    printf ("Nombre: %s\r\n", (p +i)->nombre);
    printf ("Edad: %d\r\n", (p +i)->edad);
    printf ("Sexo: %c\r\n", (p +i)->sexo);
  }
}

void ordenar(struct persona* p, int dataCant){

  //Burbujeo
  struct persona temporal;

	for (int i = 0;i < dataCant; i++){
		for (int j = 0; j< dataCant-1; j++){
			if (strcmp((p+j)->nombre,(p+j+1)->nombre) < 0){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
      memcpy(&temporal,(p+j),sizeof(struct persona));
      //strcpy(temporal,(p+j)->nombre);
      memcpy((p+j),(p+j+1),sizeof(struct persona));
      //strcpy((p+j)->nombre,(p+j+1)->nombre);
      memcpy((p+j+1),&temporal,sizeof(struct persona));
      //strcpy((p+j+1)->nombre,temporal);
			}
		}
	}
}


struct estudiante* ingreso_estudiante(int dataCant){
char nombre[16];
int nota_aux=0;
  struct estudiante* ptr_a_devolver;
  //--Pido memoria para las estructs--
  ptr_a_devolver = (struct estudiante*)malloc (sizeof(struct estudiante)*dataCant);
  if (ptr_a_devolver == NULL) {
    printf("Error pidiendo memoria para las estructuras\n");
    return (NULL);
  }
  //-- Inicializo la estructura --
  for (int i = 0; i < dataCant; i++) {
    printf ("Ingrese nombre del estudiante:\r\n");
    scanf ("%s", &nombre[0]);
    strcpy ((ptr_a_devolver +i)->nombre, nombre);
    (ptr_a_devolver +i)->cantFinales=0;
    int j=(ptr_a_devolver +i)->cantFinales;
    while ((getchar()) != '\n');//limpio el buffer
    printf("Ingrese la nota del final:\n");
    scanf("%d", &nota_aux);
     while(nota_aux != -1){

      (ptr_a_devolver +i)->final=(struct finales *)realloc((ptr_a_devolver +i)->final,sizeof(struct finales)*((ptr_a_devolver +i)->cantFinales+1));
      if ((ptr_a_devolver +i)->final==NULL) {
        printf("Error pidiendo memoria para los finales\n");
      }
      while ((getchar()) != '\n');//limpio el buffer
      printf ("Ingrese el nombre de la materia:\r\n");
      scanf ("%s", &nombre[0]);
      strcpy((ptr_a_devolver +i)->final[j].materia,nombre);
      (ptr_a_devolver +i)->final[j].nota=nota_aux;
      while ((getchar()) != '\n');//limpio el buffer
      printf("Ingrese la nota del final:\n");
      scanf("%d", &nota_aux);
      (ptr_a_devolver +i)->cantFinales++;
      j++;
      //printf("(ptr_a_devolver +%d)->final[%d].nota=%d\n",i,j,(ptr_a_devolver +i)->final[j-1].nota);
    }
    }

  return ptr_a_devolver;
}

void liberar(struct persona *p, int dataCant){
  for (int i = 0; i < dataCant; i++) {
    free((p+i)->nombre);
  }
  free(p);
}

void imprimir_estudiante(struct estudiante* p,int dataCant){
  for (int i = 0; i < dataCant; i++) {
    printf("Nombre: %s\n", (p+i)->nombre);
    printf("Cantidad de Finales del Estudiante:%d\n", (p+i)->cantFinales);
    for (int j = 0; j < (p+i)->cantFinales; j++) {
      printf("Materia:%s\n", (p+i)->final[j].materia);
      printf("Nota:%d\n", (p+i)->final[j].nota);
    }
  }
}

void liberar_estudiante(struct estudiante *p, int dataCant){
  for (int i = 0; i < dataCant; i++) {//tengo tantos punteros a finales como personas
    free((p+i)->final);
  }
  free(p);
}

void ordenar_estudiante(struct estudiante* p, int dataCant){

  //Burbujeo
  struct estudiante temporal;

	for (int i = 0;i < dataCant; i++){
		for (int j = 0; j< dataCant-1; j++){
			if ((p+j)->cantFinales < (p+j+1)->cantFinales){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
      memcpy(&temporal,(p+j),sizeof(struct estudiante));
      memcpy((p+j),(p+j+1),sizeof(struct estudiante));
      memcpy((p+j+1),&temporal,sizeof(struct estudiante));
			}
		}
	}
}

int buscar(struct estudiante* p, int dataCant,char* nombre,char* materia){
  for (int i = 0; i < dataCant; i++) {//recorro los estudiantes
    //printf("(p+i)->nombre:%s\n",(p+i)->nombre);
    //printf("nombre:%s\n",nombre );
    if (strcmp((p+i)->nombre,nombre)==0) {
      for (int j = 0; j < (p+i)->cantFinales; j++) {//recorro los finales por estudiante
        if (strcmp((p+i)->final[j].materia,materia)==0) {
          printf("Encontre al alumno y la materia.\n");
          return((p+i)->final[j].nota);
        }
        if (j+1==(p+i)->cantFinales){
        printf("No encontre la materia pero si al estudiante\n");
        return(-2);
        }
      }

    }
    if (i+1==dataCant) {
      printf("No encontre el estudiante\n");
      return(-1);
    }
  }
  printf("Si llegue aca tengo un problemon!\n");
  return(-3);
}
