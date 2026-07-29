CC ?= cc

STANDARD_FLAGS := -std=c11 -Wall -Wextra -Wpedantic
OPT_FLAGS ?= -O2
LDLIBS := -lm $(LDLIBS)

TARGET := lab5
OBJECTS := main.o convolution.o

.PHONY: all test perf perf-quick sanitize clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

main.o: main.c convolution.h
	$(CC) $(CPPFLAGS) $(STANDARD_FLAGS) $(OPT_FLAGS) $(CFLAGS) -c $< -o $@

convolution.o: convolution.c convolution.h
	$(CC) $(CPPFLAGS) $(STANDARD_FLAGS) $(OPT_FLAGS) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET) --test

perf-quick: $(TARGET)
	./$(TARGET) --perf 1 1 2048

perf: $(TARGET)
	./$(TARGET) --perf 5 1 8192

sanitize:
	$(MAKE) clean
	$(MAKE) OPT_FLAGS=-O1 CFLAGS="-g -fsanitize=address,undefined -fno-omit-frame-pointer" LDFLAGS="-fsanitize=address,undefined" $(TARGET)
	./$(TARGET) --test
	$(MAKE) clean

clean:
	rm -f $(TARGET) $(OBJECTS)
