
BIN = tests
OBJS := $(filter-out ../main.o,$(wildcard ../*.o)) tests.o
CFLAGS = --std=c++14

.PHONY: run_tests all depend

all: $(BIN)

# depend: .depend
#
# .depend: tests.cpp
# 	rm -f ./.depend
# 	g++ --std=c++14 -MM -I.. -I. tests.cpp > ./.depend
#
# include .depend

tests.cpp: MyTestSuite.h
	cxxtestgen --error-printer -o tests.cpp MyTestSuite.h

tests.o: tests.cpp
	g++ -g -c tests.cpp $(CFLAGS) -I. -I..

$(BIN):  $(OBJS)
	g++ -o $(BIN) $(OBJS) -I. -I..

run_tests: all
	./$(BIN)
