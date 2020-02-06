#CDFLAGS=-g -fsanitize=address -fsanitize=undefined -fsanitize=bounds -fsanitize=bounds-strict -fsanitize=alignment -fsanitize=object-size
CDFLAGS=-g
CFLAGS=-Wall -Wextra -pedantic -Wno-parentheses -Wfatal-errors -Werror -std=c89 $(CDFLAGS)
LDLIBS=-lSDL
SRC=./main.c ./sdl.c


DIR?=./tmp
OUT?=a.out

build: tmp-struct
	$(CC) $(CFLAGS) $(SRC) $(LDLIBS) -o $(DIR)/$(OUT)

run:
	$(DIR)/$(OUT)

tmp-struct: _FORCE
	mkdir -p $(DIR)/

_FORCE:
