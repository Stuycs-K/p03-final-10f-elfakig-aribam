.PHONY: client server clean

compile: client.o server.o networking.o
	@gcc -o client cliet.o networking.o
	@gcc -o server server.o networking.o

client: client
	@./client

server: server
	@./server

client.o: client.c networking.h
	@gcc -Wall -c client.c

server.o: server.c networking.h
	@gcc -Wall -c server.c

networking.o: networking.c networking.h
	@gcc -Wall -c networking.c

clean:
	@rm -f *.o server client