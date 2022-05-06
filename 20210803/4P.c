#include "funciones.c"


struct hijos
{
int pid;//Número del proceso hijo generado.
char * archivo; //Nombre del archivo que utiliza dicho proceso.
int nro_arg;//Número de orden en el que fue cargado el nombre en la línea de comando.
};

void handler_SIGCHLD (int mySignal){
  printf ("El hijo pid %d termino: SIGCHLD %d\r\n", wait (NULL),mySignal);

}

int main(int argc, char *argv[]) {
  //argc-1 porque un arg es el nombre del programa
  //declaro los buffers para los hijos
  int * ptr;
  char agregado[]="_decrypt";
  int pid;
  struct hijos vector_hijos[10];

  struct sigaction s;
  //-- Relleno la estructura sigaction --
  s.sa_handler = handler_SIGCHLD;
  s.sa_flags = 0;
  sigemptyset(&s.sa_mask);
  int r = sigaction (SIGCHLD, &s, NULL);
  if (r < 0) {
  //-- Error --
  printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));
  return (-1);
  }

  //---
  //Empieza el programa
  //---

  for (int i = 0; i < argc-1; i++) {
    pid = fork();
    if (pid==0) {
      //--hijo
      //Lee el archivo guarda en ptr
      int dataCant=lectura (argv[1+i],&ptr);
      //Lo que lei lo convierto a palabra y guardo en ptr
      convertir_a_string(ptr,dataCant);
      //El string del archivo que lei lo convierto a un nuevo nombre
      int cant_nueva=strlen(argv[1+i])+strlen(agregado)+1;
      char* ptr_new_name=NULL;
      ptr_new_name=(char *) realloc(ptr_new_name,sizeof(*ptr_new_name)*cant_nueva);
      nvo_nombre(argv[1+i],ptr_new_name);
      //Escribo lo guardado en ptr en un archivo con el nuevo nombre
      FILE* fp=fopen(ptr_new_name,"w");
      if (fp==NULL) {
        printf("Error en fopen\n");
        return(-1);
      }
      int rVal=fwrite(ptr,dataCant,1,fp);
      if (rVal<0) {
          printf("Error al escribir el nuevo archivo\n");
          return -1;
        }
      sleep(5);
      return 0;
    }else{
      //--Padre
      vector_hijos[i].pid=pid;
      vector_hijos[i].archivo=argv[i+1];
      vector_hijos[i].nro_arg=i+1;
      printf("pid=%d\n", vector_hijos[i].pid);
      printf("archivo:%s\n",vector_hijos[i].archivo );
      printf("nro_arg=%d\n",vector_hijos[i].nro_arg );

    }
  }
  sleep(30);
  return 0;
}
