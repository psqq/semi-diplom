
all:

#-------------------------------------------------------------------------------
sqsemi.txt: ../prototype/sqsemi.txt
	rm -f $@ || true
	cp $< ./

# gprof-out.txt: gmon.out
# 	gprof semi > gprof-out.txt

test_sq_semi: SHELL=/bin/bash
test_sq_semi: sqsemi.txt
	time ./semi iso sqsemi.txt sqsemi.txt -int
	# gprof semi > gprof-out.txt
	# gprof2dot gprof-out.txt > gprof-out.dot
	# dot -Tpng -o gprof-out.png gprof-out.dot

#-------------------------------------------------------------------------------
s1.txt: g1.txt
	./semi tos g1.txt s1.txt

s2.txt: g2.txt
	./semi tos g2.txt s2.txt

run_bin_tests_2: s1.txt s2.txt
	./semi iso s1.txt s2.txt -log -logtofile
