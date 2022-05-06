CC=gcc
EJECUTABLE1=server.out
EJECUTABLE2=client.out
HEADERS=./include
CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
LIBS= -lm

all1: 2P_2.o funciones.o TCP_clientServer.o
			$(CC) $(LFLAGS) 2P_2.o funciones.o TCP_clientServer.o $(LIBS) -o $(EJECUTABLE1)
			./$(EJECUTABLE1) 5000 log.txt
all2: 2P_3.o funciones.o TCP_clientServer.o
			$(CC) $(LFLAGS) 2P_3.o funciones.o TCP_clientServer.o $(LIBS) -o $(EJECUTABLE2)
			./$(EJECUTABLE2) 127.0.0.1 5000
2P_2.o: 2P_2.c
			$(CC) $(CFLAGS) 2P_2.c -o 2P_2.o
2P_3.o: 2P_3.c
			$(CC) $(CFLAGS) 2P_3.c -o 2P_3.o
funciones.o: funciones.c
			$(CC) $(CFLAGS) funciones.c -o funciones.o
TCP_clientServer.o: TCP_clientServer.c
			$(CC) $(CFLAGS) TCP_clientServer.c -o TCP_clientServer.o
doxy:
			doxygen Doxyfile
			firefox ./doxy/html/index.html &
clean:
			rm -f ./*.o
			rm -f ./*.out
			rm ./doxy -rf
commit:
			git add *.c
			git status
			git commit -m "Makefile"
			git push
