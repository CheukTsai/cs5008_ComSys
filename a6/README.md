# Assignment6 - CS5008 - Zhuocai Li

## 1. Program Description and General Summary
This program is mainly a basic practice for heap-sorting, my work minly is to build 3 c file,including:
1. min_heap_int.c - helps to heapsort a integer array
2. gen_heap - helps to heapsort an array with other datatype
3. gen_heap_sort - with some other helpers, gen_heap_sort can help to heapsort the name file with
some scores created by name


## 2. Compile/run Commands
Using Makefile to directly compile and run:

./Makefile includes:

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

## 3. Example Input/output

(Updated after the server is fine)

[16 40 31 41 12 8 21 40 35 43 24 43 17 4 46 12 ]
[4 8 12 21 12 41 17 40 24 31 43 43 16 35 40 46 ]




[Score: Liam (32) has score 98
Score: Emma (28) has score 59
Score: Noah (37) has score 52
Score: Olivia (39) has score 83
Score: William (37) has score 79
Score: Ava (19) has score 54
Score: James (21) has score 76
Score: Isabella (33) has score 57
Score: Oliver (36) has score 64
Score: Sophia (10) has score 80
Score: Benjamin (34) has score 71
Score: Charlotte (21) has score 60
Score: Elijah (35) has score 97
Score: Mia (25) has score 84
Score: Lucas (31) has score 51
Score: Amelia (27) has score 93
]
[Score: Lucas (31) has score 51
Score: Noah (37) has score 52
Score: Ava (19) has score 54
Score: James (21) has score 76
Score: Mia (25) has score 84
Score: Emma (28) has score 59
Score: Charlotte (21) has score 60
Score: Sophia (10) has score 80
Score: Isabella (33) has score 57
Score: Olivia (39) has score 83
Score: Amelia (27) has score 93
Score: Elijah (35) has score 97
Score: Benjamin (34) has score 71
Score: Oliver (36) has score 64
Score: William (37) has score 79
Score: Liam (32) has score 98
]

## 4. File Description
In a6, gen_heap.c, gen_heap.h, gen_heapsort.c, gen_heapsort.h, int_helpers.c, int_helpers.h, Makefile, min_heap_int.c, min_heap_int.h, names.txt, run_gen_heapsort.c, score.c, score.h are included.

## 5. External Library Usage
stdio.h, stdlib.h, time.h is used in this program.

## 6. Any Assumption Made
An array is sorted with min-heap.

## 7. External References and Resources
- https://blog.csdn.net/u010150046/article/details/77775114
- https://www.jb51.net/article/186113.htm
- https://www.cnblogs.com/banbaibanzi/p/13339198.html
- https://zhuanlan.zhihu.com/p/68577071
- and many other resources(websites) that I failed to copy and paste.

## 8. The Tricky or Hard Part I Spent Time On
It takes over 15 hours because I first stucked in understanding all the files in the starter folder, and then I have to figure out how to finish my work locally.