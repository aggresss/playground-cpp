CC=gcc
CFLAGS=-Wall -g -c
LDFLAGS =

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)
BIN=$(OBJ:%.o=%.out)

.PHONY: all

all: $(BIN)

$(BIN):%.out:%.o FORCE
	$(CC) $< -o $@ $(LDFLAGS)

$(OBJ):%.o:%.c FORCE
	$(CC) $(CFLAGS) $< -o $@

.PHONY: FORCE
FORCE:
# FORCE can only use on $< and do not use on $^

clean:
	rm -f $(OBJ) $(BIN)
