# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall

FILE = lab1

# the build target executable:
TARGET = lab1

all: $(TARGET)

$(TARGET): $(FILE).c
	$(CC) $(CFLAGS) $(FILE).c -o $(TARGET)

clean:
	$(RM) $(TARGET)