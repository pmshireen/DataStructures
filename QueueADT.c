#include<stdio.h>
#define size 10
void insert();
void delete();
void display();
int front =-1;
int rear = -1;
int q[size];
void  main()
{
    int res;
    int check = 1;
    printf("Queue implementation using Array\n");
    do{
        printf("\nQueue Operations\n1.insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&res);
        switch(res){
            case 1:
                printf("Inserting\n");
                insert();
                break;
            case 2:
                printf("deleting an Element\n");
                delete();
                break;
            case 3:
                printf("Displaying the Queue\n");
                display();
                break;
            case 4:
                printf("Exiting....\n");
                check = 0;
                break;
           default:
                printf("Enter a Valid Option\n");
                break; 
        }
    }while(check == 1);
}

void insert()
{
    int no;
    printf("Enter the number\n");
    scanf("%d",&no);
    if(rear<size-1)
    {
        q[++rear]=no;
        if(front == -1)
        front=0;
    }
    else
    printf("Queue Overflow\n");

}
void delete()
{
    if(front == -1)
    {
	
    printf("Queue underflow\n");
    return;
    }
    else
    printf("deleted item is %d",q[front]);
    if(front == rear)
    {
    front=-1;
    rear=-1;
    }
    else
    front = front+1;
}
void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;

    }
    else
    {
        for(i=front;i<=rear;i++)
        printf("\t%d",q[i]);
        
    }
}

