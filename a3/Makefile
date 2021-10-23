all: run clean 

compile, sort: main.c sort.h sort.c linkedlist.h linkedlist.c 
	gcc sort.c linkedlist.c main.c -o sort
	
run: sort
	./sort
	
.PHONY: compile clean

clean:
	 rm -rf sort