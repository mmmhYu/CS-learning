CC = gcc
CFLAGS = -Wall -g
OBJ = main.o func.o
TARGET = main

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c func.h
	$(CC) $(CFLAGS) -c main.c

func.o: func.c func.h
	$(CC) $(CFLAGS) -c func.c

clean:
	rm -f $(OBJ) $(TARGET)