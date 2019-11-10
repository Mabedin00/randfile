all: main.o random.o
	gcc -o program main.o random.o

main.o: main.c random.h
	gcc -c main.c

random.o: random.c random.h
	gcc -c random.c

run:
	./program

clean:
	rm program
	rm *.o
