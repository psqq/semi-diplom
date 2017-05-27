
BIN = tests
OBJS := $(filter-out ../obj/main.o,$(wildcard ../obj/*.o)) tests.o
CFLAGS = --std=c++14 -I. -I../src/

.PHONY: run_tests all

all: tests.cpp

# depend: .depend
#
# .depend: tests.cpp
# 	rm -f .depend
# 	g++ $(CFLAGS) -MM tests.cpp > .depend
#
# include .depend

tests.cpp: MyTestSuite.h
	cxxtestgen --error-printer -o tests.cpp MyTestSuite.h

tests.o: tests.cpp
	g++ -g -c tests.cpp $(CFLAGS)

$(BIN):  $(OBJS)
	g++ -o $(BIN) $(OBJS)

run_tests: all
	./$(BIN)
