CC=gcc
EJECUTABLE1=server.out
EJECUTABLE2=client.out
HEADERS=./include
CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
LIBS= -lm

all1: server.o funciones.o TCP_clientServer.o
			$(CC) $(LFLAGS) server.o funciones.o TCP_clientServer.o $(LIBS) -o $(EJECUTABLE1)
			./$(EJECUTABLE1) 5000
all2: client.o funciones.o TCP_clientServer.o
			$(CC) $(LFLAGS) client.o funciones.o TCP_clientServer.o $(LIBS) -o $(EJECUTABLE2)
			./$(EJECUTABLE2) 127.0.0.1 5000 posiciones.dat
client.o:
			$(CC) $(CFLAGS) 2P_2.c -o client.o
server.o:
			$(CC) $(CFLAGS) 2P_1.c -o server.o
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
			rm *.txt
			clear
commit:
			git add *.c
			git status
			git commit -m "Makefile"
			git push
