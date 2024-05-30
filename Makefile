CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDE_DIR = include
SRC_DIR = src
OBJS = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/board.c 
TARGET = bataille_navale.exe

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@

clean:
	rm -f $(TARGET)
