
FLAGS := -g --std=c++14

gi: clear_screen graph_iso

clear_screen:
	clear
	clear

graph_iso: digraph.o graph_iso.o
	g++ $(FLAGS) -o graph_iso graph_iso.o digraph.o

graph_iso.o: graph_iso.cpp digraph.h
	g++ $(FLAGS) -c graph_iso.cpp

digraph.o: digraph.cpp digraph.h
	g++ $(FLAGS) -c digraph.cpp
