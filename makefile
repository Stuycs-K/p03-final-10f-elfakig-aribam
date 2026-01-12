compile: wordle.o
	@gcc wordle.o -o prog

wordle.o: wordle.c
	@gcc -c wordle.c

run: prog
	@./prog
clean:
	@rm *.o prog
