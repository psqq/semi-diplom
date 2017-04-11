
all: prepare app/semi

prepare:
	make -C code

app/semi: code/semi
	cp code/semi app/

runapp:
	cd app; node main.js
