#include<stdio.h>
#define MAX 10
void create();
void insert();
void delete();
void search();
void display();
int n,p,e,b[20],a,i;
int pos,num;
int opt,ch;

void main()
{
	
	
	do
	{
		printf("1.create\n2.Delete\n3.serach\n4.insert\n5.dipslay\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				delete();
				break;
			case 3:
				search();
				break;
			case 4:
				insert();
				break;
			case 5:
			display();
			break;	
			default:
			printf("Enetr the valid choice");
		}
		printf("press 1 to continue and 0 to exit\n");
		scanf("%d",&opt);
	}while(opt==1);
}
void create()
{

	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elmets one by one\n");
	{
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		
	}
	
}
void delete()
{
	
printf("Enter the position to delete the element\n");  //Time complexity is O(n)
scanf("%d",&pos);
printf("Element to be deleted is %d\n",b[pos-1]);

	for(i=pos-1;i<n;i++)
	{
			b[i] = b[i+1];
	}
n--;
printf("ELement deleted\n");
	for(i=0;i<n;i++)
	{
     	printf("%d\n",b[i]);
	}
}
	
void search()

{
printf("ENter the elemnt to be searched\n");
scanf("%d",&e);
for(i=0;i<n;i++)
{
    if(b[i] == e)
    {
	
     printf("element present at position %d\n",i+1);
    }

}
}
printf("element not present\n");
void insert()
{
	printf("Enter a number to insert\n");
	scanf("%d",&num);
	printf("Enter the position to insert\n"); 
	scanf("%d",&pos);
    for(i = n-1; i >= pos-1 ; i--)
	{
		b[i+1] = b[i];
	}
	b[pos-1] = num;
	n++;
}
void display()
{
printf("ELemnts are\n");
for(i=0;i<n;i++)
    {
	 printf("%d\n",b[i]);
	}
}
