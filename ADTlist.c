#include<stdio.h>

#define MAX 10
void create();
void insert();
void del();
void search();
void display();
int n,p,e,b[20],a,i;
int pos,num;
int opt,ch;

void main()
{
	int check = 1;
	
	
	do
	{
		printf("1.create\n2.Delete\n3.search\n4.insert\n5.dipslay\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				del();
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
			case 6:
			       check = 0;
				   printf("Exiting!.......\n");			
			default:
			printf("Enetr the valid choice");
		}
		
	}while(check == 1);
}

void create()
{
    
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&b[i]);
    }
}
void del()
{
    printf(" Enter the position to delete\n");
    scanf("%d",&pos);
    printf("the element to be deleted is %d",b[pos-1]);
    for(i=pos-1;i<n;i++)
    {
        b[i+1] = b[i];
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
printf("element not present\n");
}

void insert()
{
    int num;
    printf("Enter the number to insert\n");
    scanf("%d",&num);
    printf("Enter the position to insert\n");
    scanf("%d",&pos);
    for(i=n-1;i >= pos-1;i--)
    {
        b[i+1] = b[i];
    }
    b[pos-1] = num;
    n++;
}
void display()
{
	printf("Displaying elements\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",b[i]);
	}
}
