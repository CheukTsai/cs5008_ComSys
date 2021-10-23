all: create min_heap_int

run: create
	./run_gen_heapsort

run_min_heap_int: min_heap_int
	./min_heap_int

create: run_gen_heapsort.c gen_heapsort.o heap.o score.o int_helpers.o
	gcc -g run_gen_heapsort.c gen_heapsort.c gen_heap.c score.c int_helpers.c -o run_gen_heapsort

min_heap_int: min_heap_int.o
	gcc min_heap_int.c -o min_heap_int

gen_heapsort.o: gen_heapsort.h gen_heapsort.c
	gcc -c gen_heapsort.c

heap.o: gen_heap.c gen_heap.h
	gcc -c gen_heap.c

score.o: score.c score.h
	gcc -c score.c

int_helpers.o: int_helpers.c int_helpers.h
	gcc -c int_helpers.c

min_heap_int.o: min_heap_int.c min_heap_int.h
	gcc -c min_heap_int.c
	
clean:
	rm -f *.o
	rm -f ./min_heap_int
	rm -f ./run_gen_heapsort