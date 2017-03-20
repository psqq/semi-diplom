
.PHONY: run_tests

all: tests

tests: tests.c
	gcc --std=c11 -o $@ $< -lcunit

run_tests: tests
	./tests
