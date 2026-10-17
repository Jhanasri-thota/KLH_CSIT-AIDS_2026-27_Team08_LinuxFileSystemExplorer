CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -pthread

TARGET = file_explorer

SOURCES = main.c \
          filesystem/directory_operations.c \
          filesystem/file_operations.c \
          filesystem/file_info.c \
          process/process_operations.c \
          ipc/pipe_operations.c \
          ipc/fifo_operations.c \
          ipc/signal_operations.c \
          memory/memory_operations.c \
          threads/thread_operations.c

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
