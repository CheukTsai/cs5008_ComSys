all: run

build: a2.c a2.h a2_test.c
	gcc a2.c a2_test.c -o a2

run: build
	./a2

test: build
	./a2

clean: 
	rm a2
