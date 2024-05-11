

CC=clang
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
CFLAGS=-g -Wall
BINDIR=bin
BIN = $(BINDIR)/main

TEST=test
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%.o, $(TESTS))

all:$(BIN)

clean:
	$(RM) -r $(OBJ)/* $(BINDIR)/*

test:  $(LIB) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -lcriterion

$(OBJ):
	mkdir $@

$(TEST)/bin:
	mkdir $@
