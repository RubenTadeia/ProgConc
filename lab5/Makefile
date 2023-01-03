# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -pedantic

LIBS = -pthread -lpthread

# Files
#FILE1 = lab5-pipe-example
#FILE2 = lab5-serial-prime
FILE1 = exercise-1
FILE2 = exercise-2
FILE3 = exercise-3-a
FILE4 = exercise-2-mod
FILE5 = exercise-3-a-mod
FILE6 = exercise-3-b
FILE7 = exercise-4
FILE8 = exercise-5
FILE9 = exercise-3-b-mod

# the build of all the binary executables:
BINARY1 = exercise-1
BINARY2 = exercise-2
BINARY3 = exercise-3-a
BINARY4 = exercise-2-mod
BINARY5 = exercise-3-a-mod
BINARY6 = exercise-3-b
BINARY7 = exercise-4
BINARY8 = exercise-5
BINARY9 = exercise-3-b-mod

# MAKE all
all: $(BINARY1) $(BINARY2) $(BINARY3) $(BINARY4) $(BINARY5) $(BINARY6) $(BINARY7) $(BINARY8) $(BINARY9)

$(BINARY1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY1) $(LIBS)

$(BINARY2): $(FILE2).c
	$(CC) $(CFLAGS) $(FILE2).c -o $(BINARY2) $(LIBS)

$(BINARY3): $(FILE3).c
	$(CC) $(CFLAGS) $(FILE3).c -o $(BINARY3) $(LIBS)

$(BINARY4): $(FILE4).c
	$(CC) $(CFLAGS) $(FILE4).c -o $(BINARY4) $(LIBS)

$(BINARY5): $(FILE5).c
	$(CC) $(CFLAGS) $(FILE5).c -o $(BINARY5) $(LIBS)

$(BINARY6): $(FILE6).c
	$(CC) $(CFLAGS) $(FILE6).c -o $(BINARY6) $(LIBS)

$(BINARY7): $(FILE7).c
	$(CC) $(CFLAGS) $(FILE7).c -o $(BINARY7) $(LIBS)

$(BINARY8): $(FILE8).c
	$(CC) $(CFLAGS) $(FILE8).c -o $(BINARY8) $(LIBS)

$(BINARY9): $(FILE9).c
	$(CC) $(CFLAGS) $(FILE9).c -o $(BINARY9) $(LIBS)

# MAKE clean
clean:
	$(RM) $(BINARY1)
	$(RM) $(BINARY2)
	$(RM) $(BINARY3)
	$(RM) $(BINARY4)
	$(RM) $(BINARY5)
	$(RM) $(BINARY6)
	$(RM) $(BINARY7)
	$(RM) $(BINARY8)
	$(RM) $(BINARY9)
	