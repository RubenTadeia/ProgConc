# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -pedantic

LIBS = -pthread -lpthread

# Files
FILE1 = exercise-1

# the build of all the binary executables:
BINARY1 = exercise-1

# MAKE all
all: $(BINARY1) 

$(BINARY1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY1) $(LIBS)

# MAKE clean
clean:
	$(RM) $(BINARY1)
	