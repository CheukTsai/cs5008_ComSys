all: list

list: helpers.h helpers.c graph.h graph.c main.c 
	gcc -g -std=c99 helpers.c graph.c main.c -o list
	@echo To run: ./list

run: list
	./list

memcheck:
	valgrind --leak-check=full --show-leak-kinds=all ./list

clean:
	rm list
