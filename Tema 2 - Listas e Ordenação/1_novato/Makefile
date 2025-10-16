# Makefile simples para MOD1
CC = gcc
CFLAGS = -Wall -g -O0
TARGET = bin/mod1
SRC = mod1.c

all: dirs $(TARGET)

dirs:
	mkdir -p bin

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f bin/mod1

.PHONY: all clean dirs
