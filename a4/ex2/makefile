all: prog

prog: bstitr.o compare.o
	gcc -g -Wall -std=c99 -o prog bstitr.o compare.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c
		
bstitr.o: bstitr.c
	gcc -g -Wall -std=c99 -c bstitr.c


clean:	
	rm bstitr.o
	rm compare.o
	rm prog