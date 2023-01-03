# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -pedantic

LIBS = -pthread -lpthread

# Files
FILE1 = exercise-1
FILE2 = exercise-2
FILE3 = exercise-3
FILE4 = exercise-4

# the build of all the binary executables:
BINARY1 = exercise-1
BINARY2 = exercise-2
BINARY3 = exercise-3
BINARY4 = exercise-4

# MAKE all
all: $(BINARY1) $(BINARY2) $(BINARY3) $(BINARY4)

$(BINARY1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY1) $(LIBS)

$(BINARY2): $(FILE2).c
	$(CC) $(CFLAGS) $(FILE2).c -o $(BINARY2) $(LIBS)

$(BINARY3): $(FILE3).c
	$(CC) $(CFLAGS) $(FILE3).c -o $(BINARY3) $(LIBS)

$(BINARY4): $(FILE4).c
	$(CC) $(CFLAGS) $(FILE4).c -o $(BINARY4) $(LIBS)

# MAKE clean
clean:
	$(RM) $(BINARY1)
	$(RM) $(BINARY2)
	$(RM) $(BINARY3)
	$(RM) $(BINARY4)
	