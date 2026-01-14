# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude

# Target executable
TARGET  = srps

# Source and object files
SRC     = src/main.c \
          src/validation.c \
          src/grading.c \
          src/report.c

OBJ     = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile source files into object files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
