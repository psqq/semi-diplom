
all:

sqsemi.txt: ../prototype/sqsemi.txt
	rm -f $@ || true
	cp $< ./

gprof-out.txt: gmon.out
	gprof semi > gprof-out.txt

test_sq_semi: SHELL=/bin/bash
test_sq_semi: sqsemi.txt
	time ./semi iso sqsemi.txt sqsemi.txt
	gprof semi > gprof-out.txt
	gprof2dot gprof-out.txt > gprof-out.dot
	dot -Tpng -o gprof-out.png gprof-out.dot
