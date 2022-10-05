#include<stdio.h>
void merge(int arr[],int s,int m,int e)
{
    int size = e-s;
    int temp[size];
    int i=s;
    int j=m;
    int k=0;
    int l;
    while(i<m && j<e)
    {
        if(arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<m)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<e)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(l=0;l<size;l++)
    {
          arr[s+l] = temp[l];
    }
}
void mergeSort(int arr[],int start,int end)
{
	int mid;
	
    if(end-start == 1)
    {
        return;
    }
     mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid,end);
    merge(arr,start,mid,end);

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
    mergeSort(arr,0,n);
    printf("Merge sorted elements\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

}
