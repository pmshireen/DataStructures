#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void main()
{
	int i;
    int arr[] = {5,8,12,1,3,6,23,2,45,67};
     qsort(arr,10,sizeof(int),compare);
    //quickSort(arr,0,9);
    for(i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}
