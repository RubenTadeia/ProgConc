# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall

FILE1 = lab1
FILE2 = exercise-1
FILE3 = exercise-2
FILE4 = exercise-3
FILE5 = exercise-4
FILE6 = exercise-5

# the build of all the binary executables:
BINARY_LAB1 = lab1
BINARY_exercise1 = exercise-1
BINARY_exercise2 = exercise-2
BINARY_exercise3 = exercise-3
BINARY_exercise4 = exercise-4
BINARY_exercise5 = exercise-5

all: $(BINARY_LAB1) $(BINARY_exercise1) $(BINARY_exercise2) $(BINARY_exercise3) $(BINARY_exercise4) $(BINARY_exercise5)

$(BINARY_LAB1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY_LAB1)

$(BINARY_exercise1): $(FILE2).c
	$(CC) $(CFLAGS) $(FILE2).c -o $(BINARY_exercise1)

$(BINARY_exercise2): $(FILE3).c
	$(CC) $(CFLAGS) $(FILE3).c -o $(BINARY_exercise2)

$(BINARY_exercise3): $(FILE4).c
	$(CC) $(CFLAGS) $(FILE4).c -o $(BINARY_exercise3)

$(BINARY_exercise4): $(FILE5).c
	$(CC) $(CFLAGS) $(FILE5).c -o $(BINARY_exercise4)

$(BINARY_exercise5): $(FILE6).c
	$(CC) $(CFLAGS) $(FILE6).c -o $(BINARY_exercise5)

clean:
	$(RM) $(BINARY_LAB1)
	$(RM) $(BINARY_exercise1)
	$(RM) $(BINARY_exercise2)
	$(RM) $(BINARY_exercise3)
	$(RM) $(BINARY_exercise4)
	$(RM) $(BINARY_exercise5)