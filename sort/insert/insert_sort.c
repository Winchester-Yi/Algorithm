void insert_sort(int num, int* list. int* result)
{
	int key;
	int exchange;
	*result = *list
	for(int i = 1; i < num; i++)
	{	

		key = *(result+i) = *(list+i)
		int j = i;
		while( (key < *(result + j) ) && (j > 0))
		{
			exchange = *(result+j-1);
			*(result+j-1) = *(result + j);
			*(result + j) = exchange;
			j--;
		}
	}
}