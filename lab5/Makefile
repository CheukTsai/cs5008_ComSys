all: doStuff 

doStuff: main.c sort.h sort.c linkedlist.h linkedlist.c 
	gcc -g sort.c linkedlist.c main.c -o doStuff
	
run: doStuff
	./doStuff
 
valgrind: doStuff
	valgrind ./doStuff

checkStyle: sort.c
	clint.py sort.c
	
.PHONY: compile clean

clean:
	 rm -rf doStuff