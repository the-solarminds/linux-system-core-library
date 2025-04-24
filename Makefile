CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./include
LDFLAGS = 

SRC_DIR = src
BIN_DIR = bin
TEST_DIR = tests

LIB_SOURCES = $(SRC_DIR)/file_utils.c
TEST_SOURCES = $(TEST_DIR)/test_file_utils.c

LIB_OBJECTS = $(LIB_SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

TARGET = $(BIN_DIR)/test_file_utils

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(LIB_OBJECTS) $(TEST_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(LIB_OBJECTS) $(TEST_OBJECTS)
