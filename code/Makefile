
BIN = semi
SRCS = main.cpp digraph.cpp exceptions.cpp semiiso.cpp semilattice.cpp \
	matrix.cpp digraphiso.cpp inv3.cpp
OBJS := $(SRCS:.cpp=.o)

DEBUG = 0
ifeq ($(DEBUG), 1)
MY_DEFINES = -DDEBUG_PRINTING_FOR_IS_ISOMORPHIC
endif

PROFILER = 1
ifeq ($(PROFILER), 1)
PROFILER_FLAGS = -pg
endif

CFLAGS = --std=c++14 -g -pipe $(MY_DEFINES) $(PROFILER_FLAGS)
LINK_FLAGS = -pipe $(PROFILER_FLAGS)

.PHONY: clear_screen all clean depend run_tests t run_bin_tests bt \
	test_sq_semi sqt

all: clear_screen depend $(BIN)

clear_screen:

clean:
	rm -f *.o
	rm -f $(BIN)
	rm -f *.gch

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	g++ $(CFLAGS) -MM $^ > ./.depend;

include .depend

$(BIN): $(OBJS)
	g++ $(LINK_FLAGS) -o $(BIN) $(OBJS)

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

#-------------------------------------------------------------------------------
t: run_tests

run_tests: $(OBJS)
	cd tests; make run_tests

#-------------------------------------------------------------------------------
bt: run_bin_tests

bin_tests/$(BIN): $(BIN)
	rm -f ./bin_tests/$(BIN) || true
	cp $(BIN) ./bin_tests/

run_bin_tests: bin_tests/$(BIN)
	cd bin_tests; bats .

#-------------------------------------------------------------------------------
sqt: test_sq_semi

bin_tests/sqsemi.txt: prototype/sqsemi.txt
	rm -f $@ || true
	cp $< ./bin_tests/

test_sq_semi: SHELL=/bin/bash
test_sq_semi: bin_tests/$(BIN) bin_tests/sqsemi.txt
	cd bin_tests; time ./semi iso sqsemi.txt sqsemi.txt
