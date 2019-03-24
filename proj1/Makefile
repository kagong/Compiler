20151575: main.o util.o scan.o
	gcc -o 20151575 main.o util.o scan.o

main.o: globals.h util.h scan.h
	gcc -c -o main.o main.c

util.o: util.h globals.h util.c 
	gcc -c -o util.o util.c

scan.o: scan.h scan.c
	gcc -c -o scan.o scan.c
