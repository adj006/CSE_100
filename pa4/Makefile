# Simple makefile for P4 bogtest.cpp
# type make, then ./bogtest, 
# it doesn�t revoke the GUI, so you can add any debugging functions you want
CC=g++
CXXFLAGS=-g
LDFLAGS=-g

all: bogtest
bogtest:  boggleplayer.o boggleutil.o
boggleplayer.o: boggleutil.h baseboggleplayer.h boggleplayer.h
boggleutil.o: boggleutil.h
clean:
	rm -f bogtest  *.o core*
.PHONY: clean
