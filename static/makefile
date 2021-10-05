# #########################
# Static Libray and Linking
# #########################
CC=gcc
SDIR=src
BDIR=bin
LDIR=lib

myprog: $(SDIR)/myprog.c libmylib.a 
	$(CC) $(SDIR)/myprog.c -L$(LDIR) -lmylib -o $(BDIR)/myprog

# Create the Dependent Object Files for the Library

sum.o: $(SDIR)/sum.c $(SDIR)/mylib.h
	$(CC) -c $(SDIR)/sum.c -o $(LDIR)/sum.o

show.o: $(SDIR)/show.c $(SDIR)/mylib.h
	$(CC) -c $(SDIR)/show.c -o $(LDIR)/show.o

# Create Static Library

libmylib.a: show.o sum.o
	    ar rs $(LDIR)/libmylib.a $(LDIR)/sum.o $(LDIR)/show.o


clean:
	rm $(BDIR)/myprog
	rm $(LDIR)/libmylib.a
	rm $(LDIR)/sum.o
	rm $(LDIR)/show.o
	
