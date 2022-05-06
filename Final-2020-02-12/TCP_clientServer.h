#ifndef TCP_CLIENT_SERVER_H
#define TCP_CLIENT_SERVER_H

#define _GNU_SOURCE
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

//-- Errores --
#define TCP_OK               ((int) 0)   //!< TCP OK
#define TCP_ERR_SIGNAL       ((int) -1)  //!< Error SIGCHLD
#define TCP_ERR_GETADDR      ((int) -2)  //!< Error getaddrinfo
#define TCP_ERR_SET_SOCK     ((int) -3)  //!< Error setsockopt
#define TCP_ERR_BIND         ((int) -4)  //!< Error bind
#define TCP_ERR_LISTEN       ((int) -5)  //!< Error listen
#define TCP_ERR_CONNECT      ((int) -6)  //!< Error connect
#define TCP_ERR_RECV         ((int) -7)  //!< Error con el recv

//#define TIME_OUT    5       //!<< Habilita el timeout del read usando select
#define LISTEN_MAX  10

int TCP_server (char *port, int (*func)(int, char *));
int TCP_client (char *hostName, char *port, int (*func)(int, char *));
int TCP_write(const void *ptr, int size, int cant, int fd);
int TCP_read(void *ptr, int size, int cant, int fd);

#endif
