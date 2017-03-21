
CFLAGS = --std=c11 -I../src
OBJS := $(wildcard ../obj/*.o)
OBJS := $(filter-out ../obj/main.o,$(OBJS))
OBJS := $(filter-out ../obj/tests.o,$(OBJS))
OBJS := $(OBJS) ../obj/tests.o
SUITES := $(filter-out tests.c,$(wildcard *.c))

.PHONY: run_tests

all: tests

tests.c: SHELL:=/bin/bash
tests.c: $(SUITES)
	python3 gettests.py > tests.c

../obj/tests.o: tests.c
	gcc $(CFLAGS) -o $@ -c $<

tests: $(OBJS)
	gcc -o $@ $^ -lcunit

run_tests: tests
	./tests
