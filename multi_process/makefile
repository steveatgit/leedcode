CC=gcc
FLAG=-Wall
BUILD_DIR=./build
TARGET=pipe pipe2 namedpipe 

all: $(TARGET)

pipe:
	$(CC) $(FLAG) -o $(BUILD_DIR)/pipe pipe.c

pipe2:
	$(CC) $(FLAG) -o  $(BUILD_DIR)/pipe2 pipe2.c

namedpipe:
	$(CC) $(FLAG) -o  $(BUILD_DIR)/namedpipe namedpipe.c

clean:
	rm $(BUILD_DIR)/*  test_fifo
