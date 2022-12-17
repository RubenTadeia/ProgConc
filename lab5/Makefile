# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -pedantic

LIBS = -pthread -lpthread -lgd

# Files
FILE1 = lab5-pipe-example
FILE2 = lab5-serial-prime

# the build of all the binary executables:
BINARY1 = exercise-1
BINARY2 = exercise-2

# MAKE all
all: $(BINARY1) $(BINARY2)

$(BINARY1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY1) $(LIBS)

$(BINARY2): $(FILE2).c
	$(CC) $(CFLAGS) $(FILE2).c -o $(BINARY2) $(LIBS)

# MAKE clean
clean:
	$(RM) $(BINARY1)
	$(RM) $(BINARY2)
	