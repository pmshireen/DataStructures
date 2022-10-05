#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insert( );
void del( );
void display( );
void main()
{
int choice;
do
{
printf("\t Menu");
printf("\n 1. Insert");
printf("\n 2. Delete");
printf("\n 3. Display ");
printf("\n 4. Exit");
printf("\n Enter Your Choice:");
scanf("%d", &choice);
switch(choice)
{
case 1:
insert( ); display( ); break;
case 2:
del( ); 
display( );
break;
case 3:display( );
break;
case 4:
printf("End of Program....!!!!");
exit(0);
}}while(choice != 4);}
void insert()
{
int front = -1;
int rear = -1;
int q[SIZE];
 int SIZE = 5;
	int no;
	printf("Enter the element\n");
	scanf("%d",&no);
	if(rear<size-1)
	{
		q[rear++] = no;
	  if(front == -1)
	  front = front+1;	
	}
	else
	{
		printf("Overflow\n";)
	}
	
	
}
void del()
{
	int front = -1;
int rear = -1;
int q[SIZE];
	if(front == -1)
	printf("Underflow\n");
	return;
	else
	{
		printf("Deleted item is %d\n",&q[front]);
	}
	if (front == -1)
	front = -1;
	rear = -1;
	else
	{
		front = front+1;
	}
	void display()
	{
		int front = -1;
        int rear = -1;
        int q[SIZE];
		int i;
		if (front == -1)
		printf("Queue undeflow\n");
		else
		for(i=front;i<=rear;i++)
		printf("%d\n",q[i]);
	}
	
}

