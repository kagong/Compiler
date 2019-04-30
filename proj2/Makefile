CC = gcc
OBJS = main.o util.o scan.o parse.o
TARGET = 20151575
 

.SUFFIXES : .c .o
	 
all : $(TARGET)
	 
clean :
	rm -f $(OBJS) $(TARGET)
	rm -f scan.c
	rm -f parse.h
	rm -f parse.c
	rm -f parse.output


$(TARGET): parser scaner $(OBJS)
	$(CC) -o $@ $(OBJS)

scaner: cm.l
	flex -o scan.c cm.l
parser: cm.y
	bison -o parse.c -dv cm.y

main.o: globals.h util.h scan.h parse.h
util.o: util.h globals.h util.c
scan.o: globals.h util.h scan.h parse.h scan.c
parse.o: globals.h util.h parse.h scan.h parse.c
