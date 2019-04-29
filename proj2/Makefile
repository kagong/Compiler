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

scan.c: cm.l
	flex -o scan.c cm.l
parse.c: cm.y
	bison -d -o parse.c cm.y

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: globals.h util.h scan.h parse.h
util.o: util.h globals.h util.c
scan.o: globals.h util.h scan.h parse.h cm.l
parse.o: globals.h util.h parse.h scan.h cm.y 
