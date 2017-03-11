
BIN = tests
OBJS := $(filter-out ../main.o,$(wildcard ../*.o)) tests.o

all: $(BIN)

.PHONY: run_tests

tests.cpp: MyTestSuite.h
	cxxtestgen --error-printer -o tests.cpp MyTestSuite.h

tests.o: tests.cpp
	g++ -g -c tests.cpp --std=c++14 -I. -I..

$(BIN): $(OBJS)
	g++ -o $(BIN) $(OBJS) -I. -I..

run_tests: $(BIN)
	./$(BIN)
