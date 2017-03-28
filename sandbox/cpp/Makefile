BINS = 1 2 3 4
RUN = 4

all: $(BINS) run

%: %.cpp
	g++ -o $@ --std=c++14 $<

run:
	./$(RUN)
