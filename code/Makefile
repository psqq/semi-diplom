
BIN = semi
SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))

# configuration
DEBUG_PRINTING = 1
PROFILER = 1

# USE_PRECOMILE_HEADERS = 1

# create CFLAGS
ifeq ($(DEBUG_PRINTING), 1)
MY_DEFINES = -DDEBUG_PRINTING_FOR_IS_ISOMORPHIC
endif

ifeq ($(PROFILER), 1)
PROFILER_FLAGS = -pg
endif

# ifeq ($(USE_PRECOMILE_HEADERS), 1)
# CFLAGS += # -fexceptions # -H
# endif

CFLAGS = --std=c++14 -g -pipe $(MY_DEFINES) $(PROFILER_FLAGS)
LINK_FLAGS = -pipe $(PROFILER_FLAGS)

#-------------------------------------------------------------------------------
.PHONY: clear_screen all clean depend run_tests t run_bin_tests bt \
	test_sq_semi sqt

all: clear_screen depend $(BIN)

clear_screen:

clean:
	rm -f *.o
	rm -f $(BIN)
	rm -f *.gch

#-------------------------------------------------------------------------------
depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	g++ $(CFLAGS) -MM $^ > ./.depend;

include .depend

#-------------------------------------------------------------------------------
$(BIN): $(OBJS)
	g++ $(LINK_FLAGS) -o $(BIN) $(OBJS)

obj/%.o: src/%.cpp
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

test_sq_semi: bin_tests/$(BIN)
	make -C ./bin_tests/ test_sq_semi

# bin_tests/sqsemi.txt: prototype/sqsemi.txt
# 	rm -f $@ || true
# 	cp $< ./bin_tests/
#
# bin_tests/gprof-out.txt: bin_tests/gmon.out
# 	cd bin_tests; gprof semi > gprof-out.txt
#
# test_sq_semi: SHELL=/bin/bash
# test_sq_semi: bin_tests/$(BIN) bin_tests/sqsemi.txt
# 	cd bin_tests; time ./semi iso sqsemi.txt sqsemi.txt
