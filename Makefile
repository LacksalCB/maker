CC = gcc

SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build
BIN_DIR = bin

EXEC = $(BIN_DIR)/maker
LOGS = $(wildcard $(LOG_DIR)/*.txt)

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)

CFLAGS = -g -Og -Wall -Wextra -pedantic -fsanitize=address
LDFLAGS = -g -Og -Wall -Wextra -pedantic -fsanitize=address 

.PHONY: all clean install

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) -c $< -o $@ $(CFLAGS)

install:
	cp $(EXEC) /usr/local/bin/
	mkdir -p /usr/local/lib/templates/maker_templates && cp -r templates /usr/local/lib/templates/maker_templates

clean:
	-rm $(EXEC)
	-rm $(OBJECTS)

