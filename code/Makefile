
FLAGS := -g --std=c++14

gi: graph_iso

iso: gi
	./graph_iso 1.dig 2.dig > output-iso.txt

info:
	./graph_iso -i 1.dig > output-info.txt

clear_screen:
	clear
	clear

graph_iso: clear_screen digraph.o graph_iso.o
	g++ $(FLAGS) -o graph_iso graph_iso.o digraph.o

graph_iso.o: graph_iso.cpp digraph.h
	g++ $(FLAGS) -c graph_iso.cpp

digraph.o: digraph.cpp digraph.h
	g++ $(FLAGS) -c digraph.cpp
