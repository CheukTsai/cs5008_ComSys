all: run

compile, sort: main.c sort.h sort.c
	gcc sort.c main.c -o sort
	
run: sort
	
.PHONY: compile clean

valgrind: sort
	valgrind ./sort
 
clean:
	 rm -rf sort