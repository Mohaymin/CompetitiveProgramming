#include<stdio.h>
#include<string.h>

void printArray(int arr[], int len)
{
    int i=0;
    for(i=0; i<len; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
}

int main()
{
    int arrLen = 15;
    int totalNoOfElementsToBeInitialized = 6;

    int arr[arrLen];
    printArray(arr, arrLen);
    memset(arr, -1, totalNoOfElementsToBeInitialized*sizeof(arr[0]));
    printArray(arr, arrLen);
    memset(arr, 0, totalNoOfElementsToBeInitialized*sizeof(arr[0]));
    printArray(arr, arrLen);
    memset(arr, 1, totalNoOfElementsToBeInitialized*sizeof(arr[0]));
    printArray(arr, arrLen);
    memset(arr, 2, totalNoOfElementsToBeInitialized*sizeof(arr[0]));
    printArray(arr, arrLen);
    memset(arr, -2, totalNoOfElementsToBeInitialized*sizeof(arr[0]));
    printArray(arr, arrLen);
    return 0;
}
