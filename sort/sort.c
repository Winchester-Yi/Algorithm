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
	merge_sort_(0, int num, int *array, int *sortedArray)
}

int merge_sort_(int begin, int end, int *array, int *sortedArray)
{
	if(begin < end)
	{
		int middle;
		middle = ceil(((float)end+begin)/2);
		merge_sort(begin, middle, array);
		merge_sort(middle+1, end, array);
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