CC = gcc
OBJS = main.o util.o scan.o cm.tab.o symtab.o analyze.o 
TARGET = 20151575
 

.SUFFIXES : .c .o
	 
all : $(TARGET)
	 
clean :
	rm -f $(OBJS) $(TARGET)
	rm -f scan.c
	rm -f cm.tab.*
	rm -f cm.output


$(TARGET): parser scaner $(OBJS)
	$(CC) -o $@ $(OBJS)

scaner: cm.l
	flex -o scan.c cm.l
parser: cm.y
	bison -dv cm.y

main.o: globals.h util.h scan.h parse.h
util.o: util.h globals.h util.c
scan.o: globals.h util.h scan.h parse.h scan.c
cm.tab.o: globals.h util.h parse.h scan.h cm.tab.h cm.tab.c 
analyze.o: analyze.h analyze.c
symtab.o: symtab.h symtab.c
