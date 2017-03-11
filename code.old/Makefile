
BIN = semi
SRCS = main.cpp digraph.cpp semilattice.cpp digraphiso.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS = --std=c++14 -g -pipe
LINK_FLAGS = -pipe

.PHONY: clear_screen all clean depend test

all: clear_screen depend $(BIN)

clear_screen:

clean:
	rm -f *.o
	rm -f $(BIN)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	g++ $(CFLAGS) -MM $^ > ./.depend;

include .depend

$(BIN): $(OBJS)
	g++ $(LINK_FLAGS) -o $(BIN) $(OBJS)

%.o: %.cpp
	g++ $(CFLAGS) -c $<

tests/semi: $(BIN)
	rm tests/$(BIN) || true
	cp $(BIN) tests/$(BIN)

test: tests/semi
	cd tests && bats .
