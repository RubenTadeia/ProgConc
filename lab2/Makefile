# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall 

LIBS = -pthread -lpthread 

FILE1 = test-threads_1

# the build of all the binary executables:
BINARY_test-threads_1 = test-threads_1

all: $(BINARY_test-threads_1) 

$(BINARY_test-threads_1): $(FILE1).c
	$(CC) $(CFLAGS) $(FILE1).c -o $(BINARY_test-threads_1) $(LIBS)

clean:
	$(RM) $(BINARY_test-threads_1)
