all: sieve.o sieve.h test.o
	gcc sieve.o test.o -lm

run:
	./a.out $(args)

clean:
	@rm -rf ./a.out *.o

sieve.o: sieve.c sieve.h
	gcc -c sieve.c -lm

test.o: test.c sieve.h
	gcc -c test.c -lm
