# Assignment12
# Assignment6 - REDO - CS5008 - Zhuocai Li

## 1. Program Description and General Summary
This program is mainly a basic practice for heap-sorting:
1. min_heap_int - helps to heapsort an integer array
2. gen_heap_sort - with some other helpers, gen_heap_sort can help to heapsort the name file with
some scores created by name

### Important:
1. Though the program can be perfectly manually compile and rum, using Makefile generates Errors as below:
```
bash-4.2$ make run_min_heap_int
./min_heap_int
[2 34 34 24 34 2 34 19 5 39 16 17 44 33 19 11 ]
[2 2 5 11 16 17 19 19 24 33 34 34 34 34 39 44 ]
make: *** [run_min_heap_int] Error 80
```
After discussing with Linni, we thought it was probably because some of the problems existing in std=c99 or others, but not able to handle. Pretty sure no problem comes up from what I have written in C files.

2. After valgrind ./run_gen_heapsort, I found errors from the STARTER CODE:
(run by valgrind --leak-check=full --track-origins=yes ./run_gen_heapsort)

```
==38884== Conditional jump or move depends on uninitialised value(s)
==38884==    at 0x4E84079: vfprintf (vfprintf.c:1635)
==38884==    by 0x4E8A4A8: printf (printf.c:34)
==38884==    by 0x40102F: PrintScore (score.c:31)
==38884==    by 0x4008D9: PrintArray (run_gen_heapsort.c:16)
==38884==    by 0x400A51: DoScoreHeapsort (run_gen_heapsort.c:48)
==38884==    by 0x400AB6: main (run_gen_heapsort.c:64)
==38884==  Uninitialised value was created by a heap allocation
==38884==    at 0x4C29F73: malloc (vg_replace_malloc.c:309)
==38884==    by 0x400F6C: CreateScore (score.c:12)
==38884==    by 0x4010D5: CreateScoreFromName (score.c:44)
==38884==    by 0x40118F: CreateArray (score.c:67)
==38884==    by 0x400A37: DoScoreHeapsort (run_gen_heapsort.c:47)
==38884==    by 0x400AB6: main (run_gen_heapsort.c:64)
==38884== 
```
This problem pops out due to following code in score.c (starter code, never self-changed):
```
void PrintScore(void* sc1) {
  Score* score = (Score*) sc1;
  printf("Score: %s (%d) has score %d\n", score->name, score->age, score->score);
}
```
After discussing with Linni, we think that this is because we input a void sc1 and try to assume that it is a Score, and it will contains fields like name, age and score.
However, Valgrind may consider that we haven't properly initialize a Score (what if sc1 is never a Score and it will not have fileds like name, age and score)
We though have ensured our input to be a Score, but Valgrind doesn't know that, and I think that's why these errors will pop out.

I have cleaned all the memories and this is the only issue found in Valgrind report, which I think it is not my problem.

```
==38884== 
==38884== HEAP SUMMARY:
==38884==     in use at exit: 0 bytes in 0 blocks
==38884==   total heap usage: 39 allocs, 39 frees, 2,442 bytes allocated
==38884== 
==38884== All heap blocks were freed -- no leaks are possible
==38884== 
==38884== For lists of detected and suppressed errors, rerun with: -s
==38884== ERROR SUMMARY: 16 errors from 1 contexts (suppressed: 0 from 0)
```

## 2. Compile/run Commands
Two diffenrent commands help to seperately compile min_heap and gen_heap:

./Makefile includes:

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

## 3. Example Input/output

### Min heap int:
```
[2 34 34 24 34 2 34 19 5 39 16 17 44 33 19 11 ]
[2 2 5 11 16 17 19 19 24 33 34 34 34 34 39 44 ]
```

### Gen heap:
```
[16 40 31 41 12 8 21 40 35 43 24 43 17 4 46 12 ]
[4 8 12 12 16 17 21 24 31 35 40 40 41 43 43 46 ]


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
Score: Isabella (33) has score 57
Score: Emma (28) has score 59
Score: Charlotte (21) has score 60
Score: Oliver (36) has score 64
Score: Benjamin (34) has score 71
Score: James (21) has score 76
Score: William (37) has score 79
Score: Sophia (10) has score 80
Score: Olivia (39) has score 83
Score: Mia (25) has score 84
Score: Amelia (27) has score 93
Score: Elijah (35) has score 97
Score: Liam (32) has score 98
]
```

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
For redoing, I almost modify the entire program, since I am more acknowledged with C and heapsorting right now. Spending about 3 hours.

It takes over 15 hours because I first stucked in understanding all the files in the starter folder, and then I have to figure out how to finish my work locally.