#compiler
CC = g++

#compiler flags
CFLAG = -Wall -g

#main script
SRC = src/main.c

#commands
build:
	mkdir build/
	$(CC) $(SRC) -o build/main $(CFLAG)

run:
	./build/main "$(CURDIR)/DataSet" 1

clean:
	rm -r -f build/*
	rmdir build

all: clean build run
