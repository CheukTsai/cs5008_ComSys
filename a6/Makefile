all: run


run: run_gen_heapsort.c gen_heapsort.o heap.o score.o int_helpers.o
	gcc -g run_gen_heapsort.c gen_heapsort.c gen_heap.c score.c int_helpers.c -o run_gen_heapsort

gen_heapsort.o: gen_heapsort.h gen_heapsort.c 
	gcc -c gen_heapsort.c 

heap.o: gen_heap.c gen_heap.h
	gcc -c gen_heap.c

score.o: score.c score.h
	gcc -c score.c

int_helpers.o: int_helpers.c int_helpers.h
	gcc -c int_helpers.c

clean: 
	rm *.o
	rm run_gen_heapsort