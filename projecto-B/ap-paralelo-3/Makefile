# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -pedantic

LIBS = -pthread -lpthread -lgd

# INPUT VARIABLE
IMAGES_FOLDER = imagens
NUMBER_OF_THREADS = 2

# Files
FUNCTIONS = functions
IMAGE_FILE = image-lib
THREADS = threads
MAIN = main

# the build of all the binary executables:
BINARY = ap-paralelo-3

# MAKE all
all: $(BINARY)

$(BINARY): $(MAIN).c $(IMAGE_FILE).c $(IMAGE_FILE).h $(FUNCTIONS).c $(FUNCTIONS).h $(THREADS).c $(THREADS).h
	$(CC) $(CFLAGS) $(MAIN).c $(IMAGE_FILE).c $(FUNCTIONS).c $(THREADS).c -o $(BINARY) $(LIBS)

# MAKE run
run:
	./$(BINARY) $(IMAGES_FOLDER) $(NUMBER_OF_THREADS)

# MAKE valgrind
valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(BINARY) $(IMAGES_FOLDER) $(NUMBER_OF_THREADS)

callgrind:
	valgrind --tool=callgrind ./$(BINARY) $(IMAGES_FOLDER) $(NUMBER_OF_THREADS)

time:
	time -p ./$(BINARY) $(IMAGES_FOLDER) $(NUMBER_OF_THREADS)

# MAKE clean
clean:
	$(RM) $(BINARY)

# MAKE clean folders
clean-data:
	rm -fr ./$(IMAGES_FOLDER)/Resize-dir ./$(IMAGES_FOLDER)/Thumbnail-dir ./$(IMAGES_FOLDER)/Watermark-dir
	