#include"insert_sort.h"
#include<stdio.h>

#define MAX_NUM 20

int main()
{
	int num[MAX_NUM];
	int result[MAX_NUM];
	int i=0;
	printf("Plese enter numbers:\n");
	do{
		scanf("%d",&num[i++]);
	}while(*(num+i-1)!= "\n");
	insert_sort(i, num, result);
	return 0;
}