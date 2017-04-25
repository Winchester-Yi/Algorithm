#include <math.h>


/*************************************************
void insert_sort(int num, int* list, int* result)

Input:the length of the array, the array
Output:the sorted array
*************************************************/
int insert_sort(int num, int* list)
{
	int key;
	for(int i = 1; i < num; i++)
	{	
		key = *(list + i);
		int j = i - 1;
		while((key < *(list + j)) && (j >= 0))
		{
			*(list + j+1) = *(list + j);
			j--;
		}
		*(list +j) = key;
	}
	return 0;
}


/*************************************************
void merge_sort(int num, int* list, int* result)

Input:the length of the array, the array
Output:the sorted array
*************************************************/
int merge_sort(int num, int *array, int *sortedArray)
{
	merge_sort_(0, int num, int *array, int *sortedArray);
	return 0;
}

int merge_sort_(int begin, int end, int *array, int *sortedArray)
{
	if(begin < end)
	{
		int middle;
		middle = ceil((float)end+begin)/2;
		merge_sort_(begin, middle, array, sortedArray);
		merge_sort_(middle+1, end, array, sortedArray);
		merge(begin, middle, end, array);
	}
	return 0;
}

int merge(int begin, int middle, int end, int *array, int *sortedArray)
{
	watch_1 = begin;
	watch_2 = middle;
	inedx = end;

	while((middle != watch_1) || (end != watch_2))
	{
		if(*(array + middle) > *(array + end))
		{
			*(sortedArray + inedx) = *(array + middle)
			middle--;
			inedx--;
		}
		else
		{
			*(sortedArray + inedx) = *(array + end)
			end--;
			inedx--;
		}
	}
	return 0;
}

/*************************************************
Max-Heap
void heap_sort(int num, int* list, int* result)

Input:the length of the array, the array
Output:the sorted array
*************************************************/
int max_heap(int *tree, int i, int heapSize)
{
	int maxIndex;
	int l = i<<1;
	int r = (i<<1)+1;
	int exchange;

	if ( (l <= heapSize) && ((*(tree+l)) > *(tree+i)) )
		maxIndex = l;
	else maxIndex = i;

	if ( (r <= heapSize) && ((*(tree+r)) > *(tree+maxIndex)) )
		maxIndex = r;

	if ( maxIndex != i )
	{
		exchange = *(tree+r);
		*(tree+r) = *(tree+maxIndex);
		*(tree+maxIndex) = exchange;
	}

	max_heap(tree, maxIndex, heapSize);

	return 0;
}

int build_max_heap(int *array, int heapSize)
{
	int i;
	for ( i=floor(heapSize/2); i>0; i-- )
		build_max_heap(array, i);
	return 0;
}

int heap_sort(int *array, int heapSize)
{
	int i;
	int exchange;

	build_max_heap(array, heapSize);
	for ( i=heapSize; i>1; i-- )
	{
		exchange = *(array+i);
		*(array+i) = *(array);
		*(array) = exchange;
		heapSize = heapSize - 1;
		max_heap(array, 1, heapSize);
	}
	return 0;
}
/*************************************************
quick_sort
int quick_sort(int *array, int size)

Input:the length of the array, the array
Output:the sorted array
*************************************************/
int partition(int *array, int head, int tail)
{
	int i;
	int exchange;

	int base = *(array+tail-1);
	int watch = head;

	for(i=head; i<tail; i++)
	{
		if( *(array+i)<base )
		{
			exchange = *(array+watch);
			*(array+watch) = *(array+i);
			*(array+i) = exchange;
			watch++;
		}

	}
	*(array+tail-1) = *(array+watch);
	*(array+watch) = base;
	return watch;
}

int _quick_sort_(int *array, int head, int tail)
{
	int partNum;
	if ( head<tail )
	{
		partNum = partition(array, head, tail);
		quick_sort(array, head, partNum-1);
		quick_sort(array, partNum+1, tail);
	}
	return 0;
}

int quick_sort(int *array, int size)
{
	_quick_sort_(array, 0, size);
	return 0;
}