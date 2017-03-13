
BIN = semi
SRCS = main.cpp digraph.cpp exceptions.cpp semiiso.cpp semilattice.cpp \
	matrix.cpp digraphiso.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS = --std=c++14 -g -pipe
LINK_FLAGS = -pipe

.PHONY: clear_screen all clean depend run_tests t

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

t: run_tests

run_tests: $(OBJS)
	cd tests; make run_tests
