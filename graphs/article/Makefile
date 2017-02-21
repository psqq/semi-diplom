
all: ex1 ex2 ex3

ex1: ex1.dot.png

ex1.dot.png: ex1.dot
	dot -Tpng -o ex1.dot.png ex1.dot

ex2: ex2.dot.png

ex2.dot.png: ex2.dot
	dot -Tpng -o ex2.dot.png ex2.dot

ex3: ex3.dot.png

ex3.dot.png: ex3.dot
	dot -Kfdp -n -Tpng -o ex3.dot.png ex3.dot

ex3.dot: make_ex3.py
	python3.5 make_ex3.py ex3.dot

zip: ex1 ex2 ex3
	zip images *.png
