#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
   int data;
   struct node *next;
};
struct node *head[TABLE_SIZE] = {NULL},*c;
void insert()
{
    int i,key;
    printf("Enter a value to insert into hash table: ");
    scanf("%d",&key);
    i=key%TABLE_SIZE;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
	newnode->next = NULL;
    if(head[i] == NULL)
    head[i] = newnode;
    else
    {
	    c=head[i];
        while(c->next != NULL)
        {  
	       c=c->next;
		}   
        c->next=newnode;
    }
}
void search()
{

    int key,index;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
	index=key%TABLE_SIZE;
	if(head[index] == NULL)
    printf("Search element not found!");
    else
   {
	   for(c=head[index];c!=NULL;c=c->next)
	   {
		     if(c->data == key)
			{
		        printf("Search element found!\n");
				break;
			}
		}
	    
		if(c == NULL)
	    printf("Search element not found!\n");
	}
}
void del()
{

    int key,index;
    printf("Enter the element to be deleted: ");
    scanf("%d",&key);
	index=key%TABLE_SIZE;
	if(head[index] == NULL)
    printf(" element not found!");
    else
   {

        c = head[index];
        if(head[index]->data == key)
		{
            if(head[index]->next == NULL)
			{
                head[index] = NULL;
                return;
            }
            head[index] = head[index]->next;
            return;
        }
        while(c != NULL && c->next->data != key)
		{
            c = c->next;
        }
	    if(c->next != NULL)
		{
	            struct node *temp = c->next;
		        if(temp->next == NULL)
				{
		            c->next = NULL;
		            free(temp);
		            return;
		        }
		        c->next = temp->next;
		        free(temp);
	    }
		if(c->next == NULL)
	    printf(" element not found!\n");
	}
}
void display()

{

    int i;
    for(i=0;i<TABLE_SIZE;i++)
    {
	   printf("\nEntries at index %d: ",i);
       if(head[i] == NULL)
	   {
	   printf("No Hash Entry!");
	   //return;
       }
	   else
	   {
	   for(c=head[i];c!=NULL;c=c->next)
	   printf("%d->",c->data);
	   }
	}
}
main()

{
	int opt,key,i;
	while(1)
	{
      printf("\n1.Insert\n2.Display\n3.Search\n4del\n5.Exit\nEnter choice:");
	  scanf("%d",&opt);
	  switch(opt)
       {
	
		    case 1:insert();break;
		    case 2:display();break;
		    case 3:search();break;
		    case 4: del();break;
		    case 5:exit(0);
	        default:
		    printf("Enter Valid Choice!");
	    }
	}

}
