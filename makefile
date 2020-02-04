#CC=gcc
# CFLAGS=-Wall -Wextra -pedantic -Wno-parentheses -std=c90 -g
# -Wno-unused-function
CFLAGS=-Wall -Wextra -pedantic -Wno-parentheses -Wfatal-errors -Werror -std=c89 -g
LDLIBS=-lSDL
SRC=./main.c


DIR?=./tmp
OUT?=a.out

build: tmp-struct
	$(CC) $(CFLAGS) $(SRC) $(LDLIBS) -o $(DIR)/$(OUT)

run:
	$(DIR)/$(OUT)

tmp-struct: _FORCE
	mkdir -p $(DIR)/

_FORCE:
