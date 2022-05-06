CC=gcc
EJECUTABLE1=server.out
EJECUTABLE2=client.out
HEADERS=./include
CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
LIBS= -lm

all1: server.o funciones.o TCP_clientServer.o
			$(CC) $(LFLAGS) server.o funciones.o TCP_clientServer.o $(LIBS) -o $(EJECUTABLE1)
			./$(EJECUTABLE1)
all2: client.o funciones.o TCP_clientServer.o
			$(CC) $(LFLAGS) client.o funciones.o TCP_clientServer.o $(LIBS) -o $(EJECUTABLE2)
			./$(EJECUTABLE2)
client.o:
			$(CC) $(CFLAGS) client.c -o client.o
server.o:
			$(CC) $(CFLAGS) server.c -o server.o
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
			rm *.log
			clear
commit:
			git add *.c
			git status
			git commit -m "Makefile"
			git push
