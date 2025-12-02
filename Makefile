CC = gcc
CFLAGS = -Wall -Wextra -O3

SRC = dhry_1.c dhry_2.c
OBJ = dhry_1.o dhry_2.o
TARGET = dhrystone

all: $(TARGET)
 
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c dhry.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
