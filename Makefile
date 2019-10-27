#----------------------------
#
# Makefile --- File for program 1 cs253
#
# Usage
# 	make all	Build the released product
# 	make clean	Remove build artifacts
#
# Author(s)
# 09/12/2019 Dominik Huffield
#
# ---------------------------

#-----Define names of all object files
	OBJS = smash.o commands.o

#-----Define names of all header files
	HDRS = smash.h

#-----Define the name of the resulting executable(s)
	EXE = smash

#-----Define options passed by make to the compiler amd which compiler to use
	CFLAGS = -Wall -std=c99
	CC = gcc

#-----Define target "all" for building the executables(s)
.PHONY: all
all: $(EXE) rules.d
 

smash: smash.o commands.o
	$(CC) $(CFLAGS) $^ -o $@
smash.o: smash.c commands.c smash.h
	$(CC) $(CFLAGS) -c $<
	$(CC) $(CFLAGS) -c commands.c
commands.o: commands.c smash.h 
	$(CC) $(CFLAGS) -c $<


rules.d: $(wildcard *.c) $(wildcard *.h)
	$(CC) -MM $(wildcard *.c) >rules.d
#-------Incorporate the auto-generated dependencies from rules.d into this Makefile
-include rules.d

#-----Rule for linking the executable product


.PHONY: clean
clean:
	rm -f $(OBJS) $(EXE) rules.d