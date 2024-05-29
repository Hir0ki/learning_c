SRC=src
OBJ=obj
MAINS=calculator.o
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
CFLAGS=-g -Wall
TESTCFLAGS=-g -Wall  
BINDIR=bin
BIN = $(BINDIR)/main

TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TEST_OBJS=$(filter-out obj/$(MAINS),$(OBJS))
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

.PHONY: all 
all: $(OBJ) $(TEST) $(BINDIR) $(BIN)


clean:
	$(RM) -r $(OBJ)/ $(BINDIR)/ $(TEST)/bin/

test:  $(LIB) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

$(OBJ):
	mkdir $@

$(TEST)/bin:
	mkdir $@

$(BINDIR):
	mkdir $@


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 


$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(TESTCFLAGS) -Wall $< $(TEST_OBJS) -o $@ -lcriterion
