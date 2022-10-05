#include<stdio.h>
void bubblesort(int [],int n);
void main()
{
	int n,i;
	
	int arr[20];
	printf("Enter the elements\n");
	scanf("%d",&n);
    
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,n);
	printf("Sorted array\n");
		for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void bubblesort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n-i-1;j++)
		{
			if(arr[j-1]>arr[j])
			{
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}

		}
	}
}
