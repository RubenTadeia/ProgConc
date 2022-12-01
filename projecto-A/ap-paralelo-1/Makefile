# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -pedantic

LIBS = -pthread -lpthread -lgd

# Files
FUNCTIONS = functions
IMAGE_FILE = image-lib
MAIN = main

# the build of all the binary executables:
BINARY = ap-paralelo-1

# MAKE all
all: $(BINARY)

$(BINARY): $(MAIN).c $(IMAGE_FILE).c $(IMAGE_FILE).h $(FUNCTIONS).c $(FUNCTIONS).h
	$(CC) $(CFLAGS) $(MAIN).c $(IMAGE_FILE).c $(FUNCTIONS).c -o $(BINARY) $(LIBS)

# MAKE run
run:
	./$(BINARY) imagens 4

# MAKE clean
clean:
	$(RM) $(BINARY)

# MAKE clean folders
clean-data:
	rm -fr ./Resize-dir ./Thumbnail-dir ./Watermark-dir
	rmdir Resize-dir Thumbnail-dir Watermark-dir
	