NAME=xn
TEST_NAME=xn_test

CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Wpedantic -Wno-unused-parameter
LDFLAGS=

SRC_DIR=src
OBJ_DIR=target
TEST_DIR=tests

SRC_FILES=$(shell find $(SRC_DIR)/ -type f -name '*.c')
SRC_FILES_WITHOUT_MAIN=$(shell find $(SRC_DIR)/ -type f ! -name 'main.c' -name '*.c')
TEST_FILES=$(shell find $(TEST_DIR)/ -type f -name '*.c')

OBJ_FILES=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:.c=.o))

all: $(NAME)

debug: CFLAGS += -DDEBUG -g
debug: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) -o $(OBJ_DIR)/$@ $^ $(LDFLAGS)
	rm -f $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<


test: $(TEST_NAME)

$(TEST_NAME): $(SRC_FILES_WITHOUT_MAIN) $(TEST_FILES)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/$@ $^ $(LDFLAGS)

.PHONY: clean run run-test

clean:
	rm -rf $(OBJ_DIR)/*

run: all
	./$(OBJ_DIR)/$(NAME) ${args}

run-test: test
	./$(OBJ_DIR)/$(TEST_NAME)