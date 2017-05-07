
MAKE_SEMILATTICES_BIN = make_semilattices
MAKE_SEMILATTICES_SRCS = make_semilattices.cpp

#-------------------------------------------------------------------------------
.PHONY: all clean

all: $(MAKE_SEMILATTICES_BIN) semi

clean:
	rm -R
	rm -f $(MAKE_SEMILATTICES_BIN)

#-------------------------------------------------------------------------------
$(MAKE_SEMILATTICES_BIN): $(MAKE_SEMILATTICES_SRCS)
	g++ --std=c++14 -o $@ $<

semi: ../code/semi
	cp $< $@

semigroups: semigroups_1_7.tar.gz
	mkdir $@ || true
	tar -xzf $< -C $@

semilattices: semigroups $(MAKE_SEMILATTICES_BIN)
	mkdir semilattices || true
	./$(MAKE_SEMILATTICES_BIN) 1 2 3 4 5 6 7 > totals.txt

images: images.py semi
	python3.5 images.py 1 2 3 4 5 6 7
