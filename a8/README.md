# Assignment8 - CS5008 - Zhuocai Li

## 1. Program Description and General Summary
This program is mainly a basic practice for printing files in a delicate way, following files are included:
1. queue.c - constructs a queue
2. stack.c - constructs a stack
3. tree.c - constructs a tree
4. main.c - acts as the main program
5. Makefile
6. header files - tree.h, queue.h, stack.h

## 2. Compile/run Commands
Using Makefile to directly compile and run:

./Makefile includes:

all:  main

main:
	gcc -g main.c tree.c stack.c queue.c -o main

run:
	./main

clean:
	rm -f main

## 3. Example Input/output

```
├─ a1
 ├─ assignment1.c
 ├─ README.md
├─ a2
 ├─ a2.c
 ├─ a2.h
 ├─ a2_test.c
 ├─ Makefile
 ├─ pointers.c
 ├─ README.md
├─ a3
 ├─ linkedlist.c
 ├─ linkedlist.h
 ├─ main.c
 ├─ Makefile
 ├─ README.md
 ├─ sort.c
 ├─ sort.h
├─ a4
 ├─ main.c
 ├─ Makefile
 ├─ README.md
 ├─ report.md
 ├─ sort
 ├─ sort.c
 ├─ sort.h
├─ a6
 ├─ gen_heap.c
 ├─ gen_heap.h
 ├─ gen_heapsort.c
 ├─ gen_heapsort.h
 ├─ int_helpers.c
 ├─ int_helpers.h
 ├─ Makefile
 ├─ min_heap_int.c
 ├─ min_heap_int.h
 ├─ names.txt
 ├─ README.md
 ├─ run_gen_heapsort.c
 ├─ score.c
 ├─ score.h
```

## 4. File Description
In a6, queue.c, queue.h, stack.c, stack.h, tree.c, tree.h, main.c, Makefile, README.md are included.

## 5. External Library Usage
stdio.h, stdlib.h, sys/stat.h, string.h, locale.h, dirent.h is used in this program.

## 6. Any Assumption Made
Files will be printed out under their directory.

## 7. External References and Resources
- https://blog.csdn.net/u010150046/article/details/77775114
- https://www.jb51.net/article/186113.htm
- https://www.cnblogs.com/banbaibanzi/p/13339198.html
- https://zhuanlan.zhihu.com/p/68577071
- and many other resources(websites) that I failed to copy and paste.

## 8. The Tricky or Hard Part I Spent Time On
It takes over 20 hours, the hard part I think is to free all the alloc'd parts.