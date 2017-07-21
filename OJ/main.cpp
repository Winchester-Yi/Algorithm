//Problem 1002
//#define _crt_secure_no_warnings
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//    int times;
//    int i;
//    char *num;
//    while ((scanf("%d", &times)) != eof)
//    {
//        num = (char *)calloc(times*2, sizeof(char));
//        for (i = 0; i<times; i++)
//        {
//            scanf("%ld%ld", num+i,num+i+1);
//        }
//        for (i = 0; i<times; i++)
//        {
//            printf("case %d:\n%ld + %ld = %ld\n\n", i+1, num[i], num[i+1], num[i] + num[i+1]);
//        }
//        free(num);
//     }
//	return 0;
//}

//Problem 1003
#define _crt_secure_no_warnings
#include <stdio.h>

int *findMaxCrossingSubarray(int *a, int low, int mid, int high);
int *findMaxSubarray(int *a, int low, int high);

int main()
{
    int *a;
    int len;

    findMaxSubarray(a,1,len);
    return 0;
}

int *findMaxCrossingSubarray(int *a,int low,int mid,int high)
{
    int i = mid;
    int j = mid+1;
    int maxLeft = mid;
    int maxRight = mid + 1;
    int result[3];//result[0]=maxLeft,result[1]=maxRight,result[0]=sum

    int leftSum=0, rightSum=0;

    while (i >= low)
    {
        if ((leftSum + *(a + i) > leftSum))
        {
            leftSum += *(a + i);
            maxLeft = i;
        }
        i--;
    }
    while (j <= high)
    {
        if ((rightSum + *(a + j)) > rightSum)
        {
            rightSum += *(a + j);
            maxRight = j;
        }
        j++;
    }
    result[0] = maxLeft;
    result[1] = maxRight;
    result[0] = leftSum + rightSum;
    return result;
}

int *findMaxSubarray(int *a,int low,int high)
{
    int mid;
    int *left;
    int *right;

    if (low == high)
    {
        result[0] = left;
        result[1] = right;
        result[2] = sum;
    }
    else
    {
        mid = (low + high) / 2;
        left = findMaxSubarray(a, low, mid);
        right = findMaxSubarray(a, mid + 1, high);
        findMaxCrossingSubarray(a, low, mid, high);
    }
    return;
}