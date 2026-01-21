# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude

# Target executable
TARGET  = srps

# Source and object files
SRC     = src/main.c \
          src/entities/student.c \
          src/entities/subject.c \
          src/entities/class.c \
          src/validation/validation.c \
          src/grading/student.c \
          src/grading/subject.c \
          src/reporting/studentResultList.c \
          src/reporting/classStats.c 

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
