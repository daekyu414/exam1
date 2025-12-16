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

.PHONY: all clean 

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(LIB_DIR)/libmyops.so.1.0
	$(CC) $< -I$(INC_DIR) -L$(LIB_DIR) -lmyops -lm -o $@

$(LIB_DIR)/libmyops.so.1.0: $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
	$(CC) -fPIC -shared -Wl,-soname=libmyops.so.1 $^ -o $@
	ln -s libmyops.so.1.0 $(LIB_DIR)/libmyops.so.1
	ln -s libmyops.so.1 $(LIB_DIR)/libmyops.so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -fPIC -c $< -I$(INC_DIR) -o $@

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/* $(LIB_DIR)/*