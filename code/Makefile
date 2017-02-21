
BIN = semi
SRCS = main.cpp digraph.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS = --std=c++14

all: depend $(BIN)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	g++ $(CFLAGS) -MM $^ > ./.depend;

include .depend

main.o:
	g++ $(CFLAGS) -c main.cpp

digraph.o:
	g++ $(CFLAGS) -c digraph.cpp

$(BIN): $(OBJS)
	g++ -o $(BIN) $(OBJS)

tests/semi: $(BIN)
	rm tests/$(BIN) || true
	cp $(BIN) tests/$(BIN)

test: tests/semi
	cd tests && bats .
