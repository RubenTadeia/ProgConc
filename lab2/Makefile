# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall 

LIBS = -pthread -lpthread 

# Files
FILE1 = test-threads_1
FILE2 = test-threads_2
FILE3 = exercise-3

# the build of all the binary executables:
BINARY_test-threads_1 = test-threads_1
BINARY_test-threads_2 = test-threads_2
BINARY_test-threads_3 = exercise-3

# MAKE all
all: $(BINARY_test-threads_1) $(BINARY_test-threads_2) $(BINARY_test-threads_3) 

$(BINARY_test-threads_1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY_test-threads_1) $(LIBS)

$(BINARY_test-threads_2): $(FILE2).c
	$(CC) $(CFLAGS) $(FILE2).c -o $(BINARY_test-threads_2) $(LIBS)

$(BINARY_test-threads_3): $(FILE3).c
	$(CC) $(CFLAGS) $(FILE3).c -o $(BINARY_test-threads_3) $(LIBS)

# MAKE clean
clean:
	$(RM) $(BINARY_test-threads_1)
	$(RM) $(BINARY_test-threads_2)
	$(RM) $(BINARY_test-threads_3)
