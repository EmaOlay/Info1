/**
	\file TCP_clientServer.c
	\brief Funciones de cliente servidor.
	\author Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.28
*/
#include "TCP_clientServer.h"

/**
	\fn void handler_SIGCHLD (int a)
	\brief Handler de SIGCHLD
    \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
    \date 2020.10.20
	\return void
*/
void handler_SIGCHLD (int mySignal)
{
int errnoBack;

    errnoBack = errno;      //-- Hago backup de errno, waitpid lo pisa --
    while (waitpid(-1, NULL, WNOHANG) > 0);
    errno = errnoBack;
    //-- wait (NULL);
}

/**
	\fn int TCP_server (char *port, int listenMax, void (*func)(void))
	\brief Crea un servidor TCP en el puerto indicado
	\author Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.28
    \param port: Puerto del servidor.
    \param listenMax: Conexiones simultaneas.
    \param func Puntero a la funcion que se ejecutara en cada conexion al servidor.
	\return Cero o un numero negativo indicando el error.
*/
int TCP_server (char *port, int (*func)(int, char *))
{
struct sigaction s;
struct addrinfo hints, *res, *p;
int rVal;
int sfd, sfdNew;
int yes = 1;
struct sockaddr_storage clientAddr;
socklen_t sockaddrSize;
char clientAddrStr[INET6_ADDRSTRLEN];

    //-- Relleno la estructura sigaction --
    s.sa_handler = handler_SIGCHLD;
    s.sa_flags = SA_RESTART;
    sigemptyset(&s.sa_mask);

    rVal = sigaction (SIGCHLD, &s, NULL);
    if (rVal < 0) {
        //-- Error --
        return (TCP_ERR_SIGNAL);
    }

    //-- Init hints --
    memset (&hints, 0, sizeof (hints));
    hints.ai_family = AF_INET;          //-- IPV4 --
    hints.ai_socktype = SOCK_STREAM;	//-- TCP --
    hints.ai_flags = AI_PASSIVE;        //-- Usa mi IP -
	hints.ai_protocol = 0;
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

    rVal = getaddrinfo (NULL, port, &hints, &res);
    if (rVal != 0) {
        return (TCP_ERR_GETADDR);
    }

	for (p = res; p != NULL; p = p->ai_next) {
		sfd = socket (p->ai_family, p->ai_socktype, p->ai_protocol);
		if (sfd != -1) {
			rVal = setsockopt (sfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (yes));
			if (rVal == -1) {
				return (TCP_ERR_SET_SOCK);
			}
			rVal = bind (sfd, p->ai_addr, p->ai_addrlen);
			if (rVal == -1) {
				close (sfd);
			} else {
				break;
			}
		}
	}

	freeaddrinfo (res);

    //-- Si  nunca dio bien el bind --
    if (p == NULL) {
        return (TCP_ERR_BIND);
    }

	rVal = listen (sfd, LISTEN_MAX);
	if (rVal == -1) {
		return (TCP_ERR_LISTEN);
	}

    while (1) {
		sockaddrSize = sizeof (clientAddr);
		sfdNew = accept (sfd, (struct sockaddr *) &clientAddr, &sockaddrSize);
		if (sfdNew != -1) {
			if (!fork ()) {
			    close (sfd);

				if (clientAddr.ss_family == AF_INET) {
                    //-- IPV4 --
					inet_ntop (clientAddr.ss_family, &(((struct sockaddr_in*)&clientAddr)->sin_addr), clientAddrStr, sizeof (clientAddrStr));
				} else {
                    //-- IPV6 --
					inet_ntop (clientAddr.ss_family, &(((struct sockaddr_in6*)&clientAddr)->sin6_addr), clientAddrStr, sizeof (clientAddrStr));
				}

                //-- Llamo al callback --
                rVal = func (sfdNew, clientAddrStr);
                close (sfdNew);
				return (rVal);
			}
		}
	}

    return (0);
}


/**
	\fn int TCP_client (char *hostName, char *port, int (*func)(int, char *))
	\brief Crea un cliente TCP y se conecta a direccion y puerto indicados
	\author Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.28
    \param hostName: Host al cual conectarse
    \param port: Puerto del servidor al cual hay que conectarse.
    \param func Puntero a la funcion que se ejecutara en cada conexion al servidor.
	\return Cero o un numero negativo indicando el error.
*/
int TCP_client (char *hostName, char *port, int (*func)(int, char *))
{
struct addrinfo hints, *res, *p;
int rVal;
int sfd;
char serverAddrStr[INET6_ADDRSTRLEN];

    //-- Init hints --
    memset (&hints, 0, sizeof (hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;	//-- TCP --

    rVal = getaddrinfo (hostName, port, &hints, &res);
    if (rVal != 0) {
        return (TCP_ERR_GETADDR);
    }

	for (p = res; p != NULL; p = p->ai_next) {
		sfd = socket (p->ai_family, p->ai_socktype, p->ai_protocol);
		if (sfd != -1) {
            rVal = connect(sfd, p->ai_addr, p->ai_addrlen);
			if (rVal == -1) {
				close (sfd);
			} else {
				break;
			}
		}
	}

    //-- Si  nunca dio bien el connect --
    if (p == NULL) {
        return (TCP_ERR_CONNECT);
    }

    if (p->ai_family == AF_INET) {
        //-- IPV4 --
        inet_ntop (p->ai_family, &(((struct sockaddr_in*)((struct sockaddr *)p->ai_addr))->sin_addr), serverAddrStr, sizeof (serverAddrStr));
    } else {
        //-- IPV6 --
        inet_ntop (p->ai_family, &(((struct sockaddr_in6*)((struct sockaddr *)p->ai_addr))->sin6_addr), serverAddrStr, sizeof (serverAddrStr));
    }

    //-- Llamo al callback --
    rVal = func (sfd, serverAddrStr);

	freeaddrinfo (res);

    return (TCP_OK);
}

/**
	\fn int TCP_write(const void *ptr, int size, int cant, int fd)
	\brief Funcion para escribir en un socket TCP
	\author Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.28
	\param ptr Puntero a los datos a enviar.
    \param size Tamanio del elemento a enviar.
    \param cant Cantidad de elementos a enviar
    \param fd file descriptor
	\return Devuelve la cantidad de bytes enviados o un numero negativo en caso de error.
*/
int TCP_write(const void *ptr, int size, int cant, int fd)
{
int rVal, cntBytes;
char *p = (char*)ptr;

	cntBytes = size * cant;
	do {
		rVal = send (fd, p, cntBytes, 0);
		if (rVal >= 0) {
			p += rVal;
			cntBytes -= rVal;
			if (cntBytes <= 0) {
				return (size * cant);
			}
		} else {
			return (-1);
		}
	} while (1);
}

/**
	\fn int TCP_read(void *ptr, int size, int cant, int fd)
	\brief Lee datos de la conexión.
	\author Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2020.10.28
    \param ptr Puntero a los datos a enviar.
    \param size Tamanio del elemento a enviar.
    \param cant Cantidad de elementos a enviar
    \param fd file descriptor
	\return Devuelve la cantidad de bytes enviados o un numero negativo en caso de error.
*/
int TCP_read(void *ptr, int size, int cant, int fd)
{
int cntBytes;
int rVal;
char *p = (char*)ptr;


	cntBytes = size * cant;

#ifdef TIME_OUT
fd_set rfds;
struct timeval tv;
int toCnt;

    toCnt = TIME_OUT;
	do {        
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);

		tv.tv_sec = 1;
		tv.tv_usec = 0;

		rVal = select(fd + 1, &rfds, NULL, NULL, &tv);

		if (rVal == -1) {
			return (-1);
		} else {
			if (FD_ISSET(fd, &rfds)) {
				//-- Leo --
				rVal = recv (fd, p, cntBytes, 0);
				if (rVal > 0) {
					cntBytes -= rVal;
					p += rVal;
					if (cntBytes <= 0) {
						return (size * cant);
					}
				} else {
					return (-3);
				}
			} else {
				//-- Time Out --
				if (toCnt-- <= 0) {
					return ((size * cant) - cntBytes);
				}
			}
		}
	} while (1);

#else
    do {
        rVal = recv (fd, p, cntBytes, 0);
        if (rVal > 0) {
            cntBytes -= rVal;
            p += rVal;
            if (cntBytes <= 0) {
                return (size * cant);
            }
        } else {
            return (-3);
        }
    } while (1);

#endif

}
