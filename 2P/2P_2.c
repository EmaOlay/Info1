#include "funciones.c"


int func(int fd, char *ip)
{
struct gps_S buffer;
int tam_buffer=128;
char parseado[tam_buffer];
int rVal;
//pruebo hardocodeado
char archivo[]="gps.dat";

  /*Logica para copiar el nombre y cambiar extension*/
  char nombre_aux[128];
  strcpy(nombre_aux, archivo);
  //cast para los warnings
  char *pos_c=strstr((const char *) nombre_aux, ".dat");
  if (pos_c==NULL) {
    //No es un .dat
    printf("No es un .dat\n");
    return -1;
  }
  //pongo \0 donde encontre el .c
  *(pos_c)='\0';
  //agrego el .cs
  strcat(nombre_aux, ".txt");
  //verifico
  printf("nombre aux=%s\n", nombre_aux);
  /*Termino la Logica para copiar el nombre y cambiar extension*/

    printf ("Conectado a: %s\r\n", ip);
    //--Abro el archivo origen
      FILE* fp1;
      fp1=fopen(archivo,"r");
      if (fp1==NULL) {
        printf("Error en fopen 1\n");
        return(-1);
      }
      //--Abro el archivo Destino
        FILE* fp2;
        fp2=fopen(nombre_aux,"w");
        if (fp2==NULL) {
          printf("Error en fopen 2\n");
          return(-1);
        }
      while(!feof(fp1)){
        rVal = fread (&buffer, sizeof(buffer), 1, fp1);
        if (rVal < 0) {
        printf ("Error al leer en el archivo\r\n");
        return (-1);
        }
        printf ("%s, %c, %s, %c, %d\r\n", buffer.lat, buffer.ns, buffer.lon, buffer.wo, buffer.satCant);
        //-- Lo paso al server que me dijeron --
        rVal = TCP_write (&buffer, sizeof(buffer), 1, fd);
        if (rVal < 0) {
        printf ("Error al escribir en el socket\r\n");
        return (-1);
        }

      //Espero respuesta
      printf ("Espero\r\n");
      rVal = TCP_read(parseado, 1, tam_buffer, fd);
      if (rVal != tam_buffer) {
          printf ("Error TCP_read\r\n");
          return (-2);
      }else{
        //Escribo al otro ARCHIVO

        //Escribo al destino
        rVal = fprintf(fp2,"%s", parseado);
        if (rVal<=0) {
          printf("Error en el fwrite\n");
        }

      }
      }

    fclose(fp1);
    fclose(fp2);
      return (0);
    }


int main(int argc, char *argv[])
{
    if (argc!=4) {
      printf("Se usa: ./2P_02.out 127.0.0.1 5000 posiciones.dat\n");
      return -1;
    }
    //-- Inicio el server --
    printf ("Iniciando cliente\r\n");
    TCP_client (argv[1], argv[2], func);
    printf ("Finalizando cliente\r\n");

    return (0);
}
