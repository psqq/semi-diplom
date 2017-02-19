
BIN = semi
SRCS = main.cpp digraph.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
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

$(BIN): main.o digraph.o
	g++ -o $(BIN) main.o digraph.o

tests/semi: $(BIN)
	rm tests/$(BIN) || true
	cp $(BIN) tests/$(BIN)

test: tests/semi
	cd tests; bats tests.bats
