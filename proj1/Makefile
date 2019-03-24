CC = gcc
OBJS = main.o util.o scan.o
TARGET = 20151575
 
.SUFFIXES : .c .o
	 
all : $(TARGET)
	 
clean :
	rm -f $(OBJS) $(TARGET)
	rm -f scan.c

scan.c: cm.l
	flex -o scan.c cm.l

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: globals.h util.h scan.h
util.o: util.h globals.h util.c
scan.o: globals.h util.h scan.h cm.l
