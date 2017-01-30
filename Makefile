
TEX_FILES=*.tex content/*.tex
LISTING_TARGETS=digraph.h.tex digraph.cpp.tex graph_iso.cpp.tex
TMP_FILES=*.log *.out *.aux content/*.aux
IMAGES=dot_graphs/ex1.dot.png

all: main.pdf

clear:
	rm $(TMP_FILES) || true

digraph.h.tex: code/digraph.h
	./tolisting.sh code/digraph.h content/code/digraph.h.tex

digraph.cpp.tex: code/digraph.cpp
	./tolisting.sh code/digraph.cpp content/code/digraph.cpp.tex

graph_iso.cpp.tex: code/graph_iso.cpp
	./tolisting.sh code/graph_iso.cpp content/code/graph_iso.cpp.tex

dot_graphs/ex1.dot.png: dot_graphs/ex1.dot
	dot -Tpng dot_graphs/ex1.dot -o dot_graphs/ex1.dot.png

main.pdf: $(TEX_FILES) $(LISTING_TARGETS) $(IMAGES)
	pdflatex main.tex
