#include<stdio.h>
#include<stdlib.h>
# define table_size 10
struct node
{
	int data;
	struct node *next;
};
struct node *head[table_size] = {NULL} , *c;
void insert()
{
	int key,i;
	printf("Enter the key to insert\n");
	scanf("%d",&key);
	i = key % table_size;
	struct node * newnode = (struct node *) malloc (sizeof(struct node));
	newnode->data =key;
	newnode->next =NULL;
		if(head[i] == NULL)
	{
		head[i]=newnode;  //**	
	}
	else
	{
		c = head[i];
		while(c->next != NULL)
		{
			c = c->next;
		}
		c->next = newnode;
	}
}
void search()
{
	int key,index;
	printf("Enter the key to insert\n");
	scanf("%d",&key);
	index = key%table_size;
	if(head[index] == NULL)
	{
		printf("Search element not found\n");
		
	}
	else
	{
		for(c = head[index];c!=NULL;c = c->next)
		{
			if(c->data == key)
			{
				printf("search elemnt found\n");
			}
		}
	}
}
void display()

{

    int i;
    for(i=0;i<table_size;i++)
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

printf("\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter choice:");

scanf("%d",&opt);

	switch(opt)
	
	{
	
	    case 1:
	
	insert();
	
	break;
	
	    case 2:
	
	display();
	
	break;
	
	    case 3:
	
	search();
	
	break;
	
	    case 4:exit(0);
	
	    default:
	
	    printf("Enter Valid Choice!");
	
	}

}

}
