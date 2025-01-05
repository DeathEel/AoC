CC = gcc
CFLAGS = -Wall -g -std=c11
TARGET = advent_of_code
SRC = *.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lrt

clean:
	rm -f $(TARGET)
