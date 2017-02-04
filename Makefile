
TEX_FILES=*.tex content/*.tex
LISTING_TARGETS=content/code/digraph.h.tex content/code/digraph.cpp.tex content/code/graph_iso.cpp.tex
TMP_FILES=*.log *.out *.aux content/*.aux
IMAGES=dot_graphs/ex1.dot.png

all: main.pdf zip

clear:
	rm $(TMP_FILES) || true

content/code/digraph.h.tex: code/digraph.h
	./tolisting.sh code/digraph.h content/code/digraph.h.tex

content/code/digraph.cpp.tex: code/digraph.cpp
	./tolisting.sh code/digraph.cpp content/code/digraph.cpp.tex

content/code/graph_iso.cpp.tex: code/graph_iso.cpp
	./tolisting.sh code/graph_iso.cpp content/code/graph_iso.cpp.tex

dot_graphs/ex1.dot.png: dot_graphs/ex1.dot
	dot -Tpng dot_graphs/ex1.dot -o dot_graphs/ex1.dot.png

main.pdf: $(TEX_FILES) $(LISTING_TARGETS) $(IMAGES)
	pdflatex main.tex

zip: content.zip

content.zip: content/graphs.tex content/semigroups.tex
	zip content content/graphs.tex content/semigroups.tex

grammar:
	hunspell -d ru_RU content/graphs.tex
	hunspell -d ru_RU content/semigroups.tex
