# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall 

LIBS = -pthread -lpthread 

# Files
FILE1 = test-threads_1
FILE2 = test-threads_2
FILE3 = exercise-3
FILE4 = exercise-4
FILE5 = exercise-5
FILE6 = test-threads_3
FILE7 = test-threads_4
FILE8 = exercise-7
FILE9 = exercise-8
FILE10 = exercise-7-paralelismo

# the build of all the binary executables:
BINARY_test-threads_1 = test-threads_1
BINARY_test-threads_2 = test-threads_2
BINARY_test-threads_3 = exercise-3
BINARY_test-threads_4 = exercise-4
BINARY_test-threads_5 = exercise-5
BINARY_test-threads_6 = exercise-6
BINARY_test-threads_7 = test-threads_4
BINARY_test-threads_8 = exercise-7
BINARY_test-threads_9 = exercise-8
BINARY_test-threads_10 = exercise-7-paralelismo

# MAKE all
all: $(BINARY_test-threads_1) $(BINARY_test-threads_2) $(BINARY_test-threads_3) $(BINARY_test-threads_4) $(BINARY_test-threads_5) $(BINARY_test-threads_6) $(BINARY_test-threads_7) $(BINARY_test-threads_8) $(BINARY_test-threads_9) $(BINARY_test-threads_10)

$(BINARY_test-threads_1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY_test-threads_1) $(LIBS)

$(BINARY_test-threads_2): $(FILE2).c
	$(CC) $(CFLAGS) $(FILE2).c -o $(BINARY_test-threads_2) $(LIBS)

$(BINARY_test-threads_3): $(FILE3).c
	$(CC) $(CFLAGS) $(FILE3).c -o $(BINARY_test-threads_3) $(LIBS)

$(BINARY_test-threads_4): $(FILE4).c
	$(CC) $(CFLAGS) $(FILE4).c -o $(BINARY_test-threads_4) $(LIBS)

$(BINARY_test-threads_5): $(FILE5).c
	$(CC) $(CFLAGS) $(FILE5).c -o $(BINARY_test-threads_5) $(LIBS)

$(BINARY_test-threads_6): $(FILE6).c
	$(CC) $(CFLAGS) $(FILE6).c -o $(BINARY_test-threads_6) $(LIBS)

$(BINARY_test-threads_7): $(FILE7).c
	$(CC) $(CFLAGS) $(FILE7).c -o $(BINARY_test-threads_7) $(LIBS)

$(BINARY_test-threads_8): $(FILE8).c
	$(CC) $(CFLAGS) $(FILE8).c -o $(BINARY_test-threads_8) $(LIBS)

$(BINARY_test-threads_9): $(FILE9).c
	$(CC) $(CFLAGS) $(FILE9).c -o $(BINARY_test-threads_9) $(LIBS)

$(BINARY_test-threads_10): $(FILE10).c
	$(CC) $(CFLAGS) $(FILE10).c -o $(BINARY_test-threads_10) $(LIBS)

# MAKE clean
clean:
	$(RM) $(BINARY_test-threads_1)
	$(RM) $(BINARY_test-threads_2)
	$(RM) $(BINARY_test-threads_3)
	$(RM) $(BINARY_test-threads_4)
	$(RM) $(BINARY_test-threads_5)
	$(RM) $(BINARY_test-threads_6)
	$(RM) $(BINARY_test-threads_7)
	$(RM) $(BINARY_test-threads_8)
	$(RM) $(BINARY_test-threads_9)
	$(RM) $(BINARY_test-threads_10)
