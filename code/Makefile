
BIN = semi
TESTS_BIN = run_tests
SRCS := $(wildcard src/*.cpp) $(wildcard src/*.h)

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
.PHONY: all reb clean \
	run_unit_tests t \
	run_bin_tests bt \
	test_sq_semi \
	sqt bt2 run_bin_tests_2 \
	demo build

all: build

clean:
	rm -R build || true
	rm -f $(BIN) $(TESTS_BIN)

#-------------------------------------------------------------------------------
build:
	mkdir build || true
	make -C tests
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make
	cp build/src/semi ./

$(BIN): $(SRCS)
	mkdir build || true
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make
	cp build/src/semi ./

reb: clean build
	# mkdir build || true
	# cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make
	# cp build/src/semi ./

#-------------------------------------------------------------------------------
t: run_unit_tests

$(TESTS_BIN): $(BIN)
	cp build/tests/tests ./$(TESTS_BIN)

run_unit_tests: $(TESTS_BIN)
	./$(TESTS_BIN)

#-------------------------------------------------------------------------------
bt: run_bin_tests

bin_tests/$(BIN): $(BIN)
	rm -f ./bin_tests/$(BIN) || true
	cp $(BIN) ./bin_tests/

run_bin_tests: bin_tests/$(BIN)
	cd bin_tests && (sh tests.sh || true)

#-------------------------------------------------------------------------------
bt2: run_bin_tests_2

run_bin_tests_2: bin_tests/$(BIN)
	make -C ./bin_tests/ run_bin_tests_2

#-------------------------------------------------------------------------------
sqt: test_sq_semi

test_sq_semi: bin_tests/$(BIN)
	make -C ./bin_tests/ test_sq_semi

#-------------------------------------------------------------------------------
demo:
	cd bin_tests && python3 demo.py
