#include "funciones.c"


int func (int fd, char *ip)
{
struct gps_S buffer;
int tam_buffer=128;
char parseo[tam_buffer];
int rVal;

    do {
        //-- Espero datos --
        printf ("Espero\r\n");
        rVal = TCP_read(&buffer, 1, sizeof(buffer), fd);
        if (rVal != sizeof(buffer)) {
            printf ("Error TCP_read\r\n");
            return (-2);
        }else{
              //if (buffer.satCant>3) {
                sprintf (parseo,"%s,%c,%s,%c,%d\r\n",buffer.lat,buffer.ns,buffer.lon,buffer.wo,buffer.satCant );
                //-- Lo escribo en el archivo que me dijeron --
                rVal = TCP_write (parseo, tam_buffer, 1, fd);
                if (rVal < 0) {
                printf ("Error al escribir en el socket\r\n");
                return (-1);
                }
              //}
            //return 0;
          }
        }
      while (1);
    return (0);
}


int main(int argc, char *argv[])
{
  if (argc!=2) {
    printf("Se usa: ./ 2P_01.out 5000\n");
    return -1;
  }
    //-- Inicio el server --
    printf ("Iniciando servidor\r\n");
    TCP_server (argv[1], func);
    printf ("Finalizando instancia del servidor: %d\r\n", getpid());

    return (0);
}
