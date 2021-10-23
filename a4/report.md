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