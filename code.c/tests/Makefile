
CFLAGS = --std=c11 -I../src
OBJS := $(wildcard ../obj/*.o)
OBJS := $(filter-out ../obj/main.o,$(OBJS))
OBJS := $(filter-out ../obj/tests.o,$(OBJS))
OBJS := $(OBJS) ../obj/tests.o

.PHONY: run_tests

all: tests

../obj/tests.o: tests.c
	gcc $(CFLAGS) -o $@ -c $<

tests: $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS) -lcunit

run_tests: tests
	./tests
