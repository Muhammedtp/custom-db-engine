# Makefile for Custom Database Engine

CC = gcc
CFLAGS = -Wall -Werror -g
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
TARGET = $(BIN_DIR)/db

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(INC_DIR)
	$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJS) $(TARGET) $(BIN_DIR)

run: all
	$(TARGET)

.PHONY: all clean run
