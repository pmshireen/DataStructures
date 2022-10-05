#include<stdio.h>
#include<stdlib.h>
void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int s = start;
    int e = end;
    int mid = (s + e)/2;
    int pivot = arr[mid];
    while(s <= e)
	{
        while(arr[s] < pivot)
        {
            s++;
        }
        while(arr[e] > pivot)
        {
            e--;
        }
        if(s <= e)
		{
            int temp  = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    quickSort(arr,start,e);
    quickSort(arr,s,end);
}
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void main()
{
      int n,i;
    int arr[20];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   quickSort(arr,0,n-1);
//    qsort(arr,n,sizeof(int),compare);
    printf("QUick sorted elements\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

}
