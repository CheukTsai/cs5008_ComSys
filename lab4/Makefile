all: run clean 

compile, greetings: goodbye.c greeting.c start.c
	gcc goodbye.c greeting.c start.c -o greetings
	
run: greetings
	./greetings
	
.PHONY: compile clean

clean:
	 rm -rf greetings