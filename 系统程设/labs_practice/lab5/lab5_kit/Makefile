CC = cc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -O2
LDFLAGS = -lm
TARGET = lab5
SRCS = main.c convolution.c

.PHONY: all clean test perf debug package

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

test: $(TARGET)
	./$(TARGET) 1 1

perf: $(TARGET)
	./$(TARGET) 5 1

debug: CFLAGS = -std=c11 -O0 -g -Wall -Wextra -pedantic
debug: clean $(TARGET)

clean:
	rm -f $(TARGET)
