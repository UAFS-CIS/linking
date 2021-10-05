# ########################################################
# Makefile for Shared Library and Dynamic Runtime Linking
# ########################################################

CC=gcc
SDIR=src
BDIR=bin
LDIR=lib

myprog: $(SDIR)/myprog.c libmylib.so 
	$(CC) $(SDIR)/myprog.c -L$(LDIR) -lmylib -o $(BDIR)/myprog

# Create the Dependent Object Files for the Library

sum.o: $(SDIR)/sum.c $(SDIR)/mylib.h
	$(CC) -c -fPIC $(SDIR)/sum.c -o $(LDIR)/sum.o

show.o: $(SDIR)/show.c $(SDIR)/mylib.h
	$(CC) -c -fPIC $(SDIR)/show.c -o $(LDIR)/show.o

# Create Shared Library

libmylib.so: show.o sum.o
	$(CC) -shared $(LDIR)/sum.o $(LDIR)/show.o -o $(LDIR)/libmylib.so 

#  Create a Executable that dynamically loads at Runtime 

runtime: $(SDIR)/runtime.c libmylib.so 
	$(CC) $(SDIR)/runtime.c -ldl -o $(BDIR)/runtime

clean:
	rm $(BDIR)/myprog
	rm $(BDIR)/runtime
	rm $(LDIR)/libmylib.so
	rm $(LDIR)/sum.o
	rm $(LDIR)/show.o

install:  
	cp $(BDIR)/myprog /usr/bin
	cp $(LDIR)/libmylib.so /usr/lib
	chmod 755 /usr/lib/libmylib.so

uninstall:  
	rm /usr/bin/myprog
	rm /usr/lib/libmylib.so
	
