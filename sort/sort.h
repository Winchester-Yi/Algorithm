#ifndef SORT
#define SORT

int insert_sort(int num, int *array);

int merge_sort(int num, int *array, int *sortedArray);

int heap_sort(int *array, int heapSize);

int quick_sort(int *array, int size);

#endif