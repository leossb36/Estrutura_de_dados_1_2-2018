#compiler
CC = gcc

#compiler flags
CFLAG = -Wall -g

#main script
SRC = src/main.c

#executable file
BUILD = build/main.o

#commands
build:
	mkdir build/
	$(CC) $(SRC) -o $(BUILD) $(CFLAG)

run:
	./build/main "$(CURDIR)/DataSet" 1

clean:
	rm -r -f build/*
	rmdir build

all: clean build run
