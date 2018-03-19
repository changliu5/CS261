all: prog

prog: animalbst.o compare.o main.o
	gcc -g -Wall -std=c99 -o prog main.o animalbst.o compare.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c
		
animalbst.o: animalbst.c animalbst.h
	gcc -g -Wall -std=c99 -c animalbst.c

main.o: main.c
	gcc -g -Wall -std=c99 -c main.c


clean:	
	rm animalbst.o
	rm compare.o
	rm prog
	rm main.o
