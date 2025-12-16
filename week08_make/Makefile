PRO_DIR=$(shell pwd)
SRC_DIR=$(PRO_DIR)/src
OBJ_DIR=$(PRO_DIR)/obj
INC_DIR=$(PRO_DIR)/include
BIN_DIR=$(PRO_DIR)/bin
LIB_DIR=$(PRO_DIR)/lib

CC=gcc
AR=ar

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: all clean basic

all: $(BIN_DIR)/myapp

basic: $(LIB_DIR)/libmybasic.a

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmybasic.a 
	$(CC) $< -L$(LIB_DIR) -lmybasic -o $@

$(LIB_DIR)/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/div.o $(OBJ_DIR)/mul.o
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -I$(INC_DIR) -o $@

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* $(LIB_DIR)/*