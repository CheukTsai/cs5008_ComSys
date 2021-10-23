# Assignment4 - CS5008 - Zhuocai Li

## 1. Program Description and General Summary
This program is mainly to conduct 4 different type of Quicksort and their performance are reflected by
the time they used when facing differnt arrays with different length.

1. README.md
2. Makefile
3. linkedlist.c
4. linkedlist.h
5. main.c
6. sort.c
7. sort.h

## 2. Compile/run Commands
Automatically compile and run by typing command: make
Other commands can be used:
./sort -a
./sort -b
./sort -c
./sort -d
./sort -ab
./sort -ac
./sort -ad
./sort -bc
./sort -bd
./sort -cd
./sort -abc
./sort -abd
./sort -bcd
./sort -all

## 3. Example Input/output

```
                16      64      128     256     512     1024    2048
-----------------------------------------------------------
Alg A:          4       17      40      71      154     321     714

Alg A (sorted): 2       20      74      284     1107    3915    10154

Alg B:          13      45      91      230     489     1058    2160

Alg B (sorted): 14      50      112     252     562     1235    2655

Alg C:          1       5       11      25      52      113     258

Alg C (sorted): 1       4       8       17      35      75      183

Alg D:          1       5       10      21      45      103     239

Alg D (sorted): 1       6       24      92      358     1399    5270

```

## 4. File Description
Following files are included:
1. README.md
2. Makefile
3. main.c
4. sort.c
5. sort.h
6. report.md

## 5. External Library Usage
stdio.h, stdlib.h, time.h, stdbool.h>, sys/time.h, unistd.h, string.h are used in this program.

## 6. Any Assumption Made
Four algorithms will show different time complexity.

## 7. External References and Resources
- http://c.biancheng.net/view/1447.html
- http://c.biancheng.net/view/1829.html
- https://zhidao.baidu.com/question/538713822.html
- https://www.cnblogs.com/yanglai/p/6927151.html
- https://www.runoob.com/cprogramming/c-function-strlen.html
- http://c.biancheng.net/c/strlen.html
- https://www.cnblogs.com/bobliao/p/9916860.html
- http://www.voidcn.com/article/p-bgpaqokq-buw.html
- https://zhidao.baidu.com/question/55742251.html
- https://blog.csdn.net/the_marvellous_yolk/article/details/90312518
- https://www.dotcpp.com/course/236
- https://blog.csdn.net/a7055117a/article/details/51049290
- https://blog.csdn.net/yukiooy/article/details/4682989?utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
- https://www.cnblogs.com/devilmaycry812839668/p/6353807.html
- https://blog.csdn.net/u013925378/article/details/88899115
- https://www.cnblogs.com/qingergege/p/5914218.html
- https://blog.csdn.net/Eastmount/article/details/20413773
- https://blog.csdn.net/micro9981/article/details/82187435
- https://blog.csdn.net/u013897132/article/details/47024035?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-4.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-4.control
- https://zhuanlan.zhihu.com/p/78846252
- and many other resources(websites) that I failed to copy and paste.

## 8. The Tricky or Hard Part I Spent Time On
I think the hardest part is to deal with the "./sort -xxx" part. I used to try getopt() and getopt_long() for over 4 hours, but it didn't come out well. So I changed to use the for loop, checking every character in the input string.

# Summary of Quicksort Application - Zhuocai Li

## The result of 4 different Algorithms (Example)
```
                16      64      128     256     512     1024    2048
-----------------------------------------------------------
Alg A:          4       17      40      71      154     321     714

Alg A (sorted): 2       20      74      284     1107    3915    10154

Alg B:          13      45      91      230     489     1058    2160

Alg B (sorted): 14      50      112     252     562     1235    2655

Alg C:          1       5       11      25      52      113     258

Alg C (sorted): 1       4       8       17      35      75      183

Alg D:          1       5       10      21      45      103     239

Alg D (sorted): 1       6       24      92      358     1399    5270

```

As we can see, 4 algorithms come out with different time complexity (in microseconds).

The main cause for this is that they have different ways of partition.

## Original Quicksort: 
it can behave well in the unsorted arrays, but for the sorted ones, it will recurse
far more than unsorted one, and the result will get worse if the number of integers increase.

## Shuffles:
Since the array keeps shuffle and the pivot at first is picked randomly, that no matter in a sorted
array or in an unsorted array, it will spend much the same time in partition. It may not be a very good approach
to do the quicksort.

## Median Pivot:
It takes three numbers a time into consider, that it will pretty much shrink the number of recursion. If the array numbers
get bigger, it will perform even better.

## Co-op with Insertion Sort:
This algorithm can perform well when the total number is small, since the Insertion Sort is much efficient when number is not that large. Otherwise, it gets much slower.