
all: run

.PHONY: run

tests.cpp: MyTestSuite.h
	cxxtestgen --error-printer -o tests.cpp MyTestSuite.h

tests: tests.cpp
	g++ -o tests tests.cpp -I.

run: tests
	./tests
