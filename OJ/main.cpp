////Problem 1003
#define _crt_secure_no_warnings
#include <stdio.h>
#include <ctype.h>

int *findMaxCrossingSubarray(int *a, int low, int mid, int high);
int *findMaxSubarray(int *a, int low, int high);

int main()
{
    int a[] = { 6, -1, 5, 4, - 7 };
    int *result;

    result=findMaxSubarray(a, 1, 5);
    printf("low:%d\nhigh:%d\nsum:%d ", *a, *(a + 1), *(a + 2));
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
    result[2] = leftSum + rightSum;
    return result;
}

int *findMaxSubarray(int *a,int low,int high)
{
    int mid;
    int *left;
    int *right;
    int *cross;

    int result[3];

    if (low == high)
    {
        result[0] = low;
        result[1] = high;
        result[2] = *(a+low);
        return result;
    }
    else
    {
        mid = (low + high) / 2;
        left = findMaxSubarray(a, low, mid);
        right = findMaxSubarray(a, mid + 1, high);
        cross = findMaxCrossingSubarray(a, low, mid, high);
        if (*(left + 2) > *(right + 2) && *(left + 2) > *(cross + 2))
            return left;
        else if (*(right + 2) > *(left + 2) && *(right + 2) > *(cross + 2))
        {
            return right;
        }
        else
            return cross;
    }
}