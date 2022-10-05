#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete();
void display();
void main()
{
     int ch;
     int check =1;
     do
     {
         printf("1.insert\n2.delete\n3.display\n");
         printf("enter the choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:insert();
                    break;
             case 2:delete();
                    break;
             case 3:display();
                    break;  

             case 4:check =0;
                    printf("Exiting!....\n");
         
         default:
               printf("Enter the  correct choice\n");
           }

     }while(check == 1);
}
void insert()
{
	//struct node * ptr;
    int item;
    struct node * ptr = (struct node *)malloc (sizeof(struct node));
    if(ptr == NULL)
    {
	
    printf("Unable to insert into queue\n");
    return;  //*
    
   }
    else
    {
        printf("Enter the value to be inserted\n");
        scanf("%d",&item);
        ptr->data = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
    printf("Value inserted\n");
}
void delete()
{
	 struct node * ptr ;
    if(front == NULL)
    {
    printf("Underflow\n");
    return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);

    }
    printf("Deleted successfully\n");

}
void display()
{
	  struct node * ptr ;
	  ptr = front;                   //**
    if(front = NULL)                //**front == NULL
	{                            
    printf("Queue is epmty\n");
    return;
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
    }
}
