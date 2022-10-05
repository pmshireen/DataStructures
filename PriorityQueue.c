#include<stdio.h>
#include<stdlib.h>
enum{FALSE=0,TRUE=-1};
struct node
{
    int data;
    struct node *previous;
    struct node *next;
}*current;
struct node *head;
struct node *ptr;
int PriorityQueue(void);
int Minimum();
int Maximum();
int Delete(int Datadel);
int Search(int DataSearch) ;
void display();
static int NumOfNodes;
void insert(int DT);

void main()
{
	//     PriorityQueue();
    int ch,DT,opt;
    int Datadel;
    int Datasearch;
    int check = 1;
    do
    {
        printf("1.Insert\n2.display\n3.Delete\n4.search\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   printf("Enter the data:");
                   scanf("%d",&DT);  
                   insert(DT);
                   break;
            case 2: display();
                    break;
            case 3:
            {
                do
                {
                   
                printf("1.Maximum Priority Queue\n2.Minimum Priroity Queue\n");

                switch(opt)
                {
                    case 1:
                           Datadel=Maximum();
						   Delete(Datadel);
						   printf("\n%d is deleted\n",Datadel);
						   break;;
                    case 2:
                           Datadel = Minimum();
                           Delete(Datadel);
                           	printf("\n%d is deleted\n",Datadel);
                           break;
                    case 3:
                            check = 0;
                            printf("Exiting!.......");
                            break;       
                }
                default :
                printf("Enter the valid choice\n");

                
                }  while(check == 1);

            }
            case 4:
            {
                printf("\nEnter a data to Search in Queue:");
				scanf("%d",&DT);
				if(Search(DT)!=FALSE)
					printf("\n %d is present in queue",DT);
				else
					printf("\n%d is not present in queue",DT);
				break;
            }
            case 5:
            check = 0;
            printf("Exiting!.........");break;
            //default :
            //printf("Enter the valid choice\n");


        } while (check == 1);

        
    }while(check == 1);
}
int PriorityQueue(void)
{
	
    current->previous = NULL;
    printf("Enter the element\n");
    scanf("%d",&current->data);
    current->next= NULL;
    head = &current;
    ptr = head;
    NumOfNodes++;
    return TRUE;
}
int Delete(int Datadel)
{
    struct node *mynode, *temp;
    ptr = head; //*
    if(ptr->data == Datadel)
    {
        temp = ptr;
        ptr = ptr->next;
        ptr->previous = NULL;
        head = ptr;
        NumOfNodes--;
        return TRUE;
    }
    else
    {
        while(ptr->next->next != NULL)
        {
            if(ptr->next->data == Datadel)
            {
                mynode = ptr;
                temp = ptr->next;
                mynode->next = mynode->next->next;
                mynode->next->previous = ptr;
                free(temp);
                NumOfNodes--;
                return TRUE;
            }
            ptr = ptr->next;
        }
        if(ptr->next->next  != NULL  && ptr->next->data == Datadel)
        {
            temp = ptr;
                                                        
            free(temp);
            ptr->next = NULL;
            NumOfNodes--; //**
            return TRUE;
        }

    }
    return(FALSE);
}
int Maximum()
{
    int temp;
    ptr = head;
    temp = ptr->data;
    while(ptr->next != NULL)
    {
      if(ptr->data > temp)
      {
          temp = ptr->data;
          ptr = ptr->next;
      }
    
    }
    if(ptr->next == NULL && ptr->data > temp)
     {
         temp = ptr->data; //*
         return temp;  //*
     }
}
int Minimum()
{
    int temp;
    ptr = head;
    temp = ptr->data;
    while(ptr->next != NULL)
    {
      if(ptr->data < temp)
      {
          temp = ptr->data;
          ptr = ptr->next;
      }
    
    }
    if(ptr->next == NULL && ptr->data < temp)
     {
         temp = ptr->data; //*
         return temp;  //*
     }
}
void insert(int DT)
{
    struct node * newnode;
    newnode = (struct node *)malloc (sizeof(struct node));
    newnode->data = DT;
    newnode->next = NULL;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if(ptr->next == NULL  )
    {
         newnode ->next = ptr->next;
         ptr->next = newnode;
    }
    NumOfNodes++;

}

int Search(int DataSearch) 
{
	
	ptr=head;
	while(ptr->next!=NULL) 
	{
		if(ptr->data==DataSearch)
			return ptr->data;
		ptr=ptr->next;
	}
	if(ptr->next==NULL && ptr->data==DataSearch)
		return ptr->data;
	return(FALSE);
}
void display() 
{
	ptr=head;
	printf("\nPriority Queue is as Follows:-\n");
	while(ptr!=NULL) 
	{
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
}




