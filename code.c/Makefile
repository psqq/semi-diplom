SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
BIN = main
CFLAGS = --std=c11

.PHONY: run_tests t

all: $(BIN)

obj/%.o: src/%.c
	gcc $(CFLAGS) -o $@ -c $<

$(BIN): $(OBJS)
	gcc -o $@ $^

t: run_tests

run_tests:
	make -C tests run_tests
