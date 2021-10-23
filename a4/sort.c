#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.h"

void Swap(int* array, int ind1, int ind2) {
  int tmp = array[ind1];
  array[ind1] = array[ind2];
  array[ind2] = tmp;
}


int Partition(int* data, int low, int high) {
  int pivot = data[low];
  int leftwall = low;
  int i;
  for (i = low + 1; i <= high; i++) {
    if (data[i] < pivot) {
      leftwall++;
      Swap(data, i, leftwall); 
    }
  }
  Swap(data, low, leftwall);
  return leftwall;
}

void Quicksort(int* data, int low, int high) {
  if (low < high) {
    int pivot_location = Partition(data, low, high);
    Quicksort(data, low, pivot_location);
    Quicksort(data, pivot_location+1, high);
  }
}

int PartitionRandom(int* data,int low,int high){
  srand(6);
  int randNum= low+ rand() % (high-low);
  Swap(data, randNum, high);
  return Partition(data,low,high);
}

void QuicksortRandom(int* data,int low,int high){
  if(low<high){
	int pivot=PartitionRandom(data,low,high);
	QuicksortRandom(data,low,pivot-1);
	QuicksortRandom(data,pivot+1,high);
  }
}

int PartitionMid(int* data, int low, int high) {
  int first = data[low];
  int last = data[high];
  int middle = data[(low + high) / 2];
  if(first <= last && last <= middle) {
      Swap(data, low, high);
  } else if (middle <= last && last <= first) {
      Swap(data, low, high);
  } else if (first <= middle && middle <= last) {
      Swap(data, low, (low + high) / 2);
  } else if (last <= middle && middle <= first) {
      Swap(data, low, (low + high) / 2);
  }
  return Partition(data, low, high);
}

void Median(int* data, int low, int high) {
  if(low<high){
	int pivot=PartitionMid(data,low,high);
	Median(data,low,pivot-1);
	Median(data,pivot+1,high);
  }
}

void InsertionSort(int* data, int low, int n){
  int i;
  for(i=low+1;i<n+1;i++){
    int val = data[i] ;
    int j = i ;
    while (j>low && data[j-1]>val){
      data[j]= data[j-1] ;
      j-= 1;
    }
    data[j]= val ;
  }
}
 
void HybridQuicksort(int* data, int low, int high){
  while (low < high){ 
	  if(high-low + 1 < 10){
	    InsertionSort(data, low, high);
	    break;
	  }else
	    {int pivot = Partition(data, low, high);
	      if (pivot-low<high-pivot){
	          HybridQuicksort(data, low, pivot - 1);
	          low = pivot + 1;
	      }else{
	         HybridQuicksort(data, pivot + 1, high);
	         high = pivot-1;
	      }
	  }
  }
}