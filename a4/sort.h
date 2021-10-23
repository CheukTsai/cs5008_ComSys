#ifndef SORT_H

#define SORT_H

void Swap(int* array, int ind1, int ind2);
int Partition(int* data, int low, int high);
void Quicksort(int* data, int low, int high);

void QuicksortRandom(int* data,int low,int high);
int PartitionRandom(int* data,int low,int high);

int PartitionMid(int* data, int low, int high);
void Median(int* data, int low, int high);

void InsertionSort(int arr[], int low, int n);
void HybridQuickSort(int arr[], int low, int high);

#endif