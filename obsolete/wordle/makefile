compile: main.o wordle.o
	gcc main.o wordle.o -o prog

main.o: main.c wordle.h
	gcc -c main.c
wordle.o: wordle.c
	gcc -c wordle.c

run: prog
	./prog
clean:
	rm *.o prog
