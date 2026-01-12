compile: main.o errorfile.o read.o wordle.o write.o
	gcc main.o errorfile.o read.o wordle.o write.o -o prog

errorfile.o: errorfile.c
	gcc -c errorfile.c
main.o: main.c errorfile.h read.h write.h
	gcc -c main.c
read.o: read.c errorfile.h
	gcc -c read.c
wordle.o: wordle.c read.h
	gcc -c wordle.c
write.o: write.c write.h
	gcc -c write.c

run: prog
	./prog
clean:
	rm *.o prog
