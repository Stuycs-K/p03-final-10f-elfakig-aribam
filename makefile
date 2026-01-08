compile: main.o write.h
	gcc main.o -o prog
main.o: main.c
	gcc -c main.c
run: prog
	./prog
clean:
	rm *.o prog
