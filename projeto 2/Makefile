#compiler
CC = gcc

#compiler flags
CFLAG = -Wall -a

#main script
SRC = /src/main.c

#executable file
BUILD = /build/main.o
exec = build/./main


#commands
build:
	mkdir build/
	$(CC) $(SRC) -o $(BUILD)

run:
	$(exec)

clean:
	rm -rf build/

all:
	build 
	run
