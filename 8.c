#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
enum {FALSE=0,TRUE=-1};
struct Node 
{
	struct Node *Previous;
	int Data;
	struct Node *Next;
} Current;
struct Node *head;
struct Node *ptr;
static int NumOfNodes;
int PriorityQueue(void);
int Maximum(void);
int Minimum(void);
void Insert(int);
int Delete(int);
void Display(void);
int Search (int);
void main() 
{
	
	int choice;
	int DT;
	PriorityQueue();
	while(1) 
	{
		printf("\nEnter ur Choice:");
		printf("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice) 
		{
			case 1:
				printf("\nEnter a data to enter Queue");
				scanf("%d",&DT);
				Insert(DT);
				break;
			case 2:
				Display();
				break;
			case 3: 
			{
				int choice,DataDel;
				printf("\nEnter ur choice:");
				printf("\n1.Maximum Priority queue\n2.Minimum priority Queue\n");
				scanf("%d",&choice);
				switch(choice) 
				{
					case 1:
						DataDel=Maximum();
						Delete(DataDel);
						printf("\n%d is deleted\n",DataDel);
						break;
					case 2:
						DataDel=Minimum();
						Delete(DataDel);
						printf("\n%d is deleted\n",DataDel);
						break;
					default:
						printf("\nSorry Not a correct Choice\n");
				    }
			}
			break;
			case 4:
				printf("\nEnter a data to Search in Queue:");
				scanf("%d",&DT);
				if(Search(DT)!=FALSE)
					printf("\n %d is present in queue",DT);
				else
					printf("\n%d is not present in queue",DT);
				break;
			case 5:
				exit(0);
			default:
				printf("\nCannot process ur choice\n");
		}
	}
}
int PriorityQueue(void) 
{
	Current.Previous=NULL;
	printf("\nEnter first element of Queue:");
	scanf("%d",&Current.Data);
	Current.Next=NULL;
	head=&Current;
	ptr=head;
	NumOfNodes++;
	return 1;
}
int Maximum(void) 
{
	int Temp;
	ptr=head;
	Temp=ptr->Data;
	while(ptr->Next!=NULL) 
	{
		if(ptr->Data>Temp)
			Temp=ptr->Data;
		ptr=ptr->Next;
	}
	if(ptr->Next==NULL && ptr->Data>Temp)
		Temp=ptr->Data;
	return(Temp);
}
int Minimum(void) 
{
	int Temp;
	ptr=head;
	Temp=ptr->Data;
	while(ptr->Next!=NULL) 
	{
		if(ptr->Data<Temp)
			Temp=ptr->Data;
		ptr=ptr->Next;
	}
	if(ptr->Next==NULL && ptr->Data<Temp)
		Temp=ptr->Data;
	return(Temp);
}
void Insert(int DT) 
{
	struct Node *newnode;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->Next=NULL;
	newnode->Data=DT;
	while(ptr->Next!=NULL)
		ptr=ptr->Next;
	if(ptr->Next==NULL) 
	{
		newnode->Next=ptr->Next;
		ptr->Next=newnode;
	}
	NumOfNodes++;
}
int Delete(int DataDel) 
{
	struct Node *mynode,*temp;
	ptr=head;
	if(ptr->Data==DataDel) 
	{
		
		temp=ptr;
		ptr=ptr->Next;
		ptr->Previous=NULL;
		head=ptr;
		NumOfNodes--;
		return(TRUE);
	} 
	else 
	{
		while(ptr->Next->Next!=NULL) 
		{
			if(ptr->Next->Data==DataDel) 
			{
				mynode=ptr;
				temp=ptr->Next;
				mynode->Next=mynode->Next->Next;
				mynode->Next->Previous=ptr;
				free(temp);
				NumOfNodes--;
				return(TRUE);
			}
			ptr=ptr->Next;
		}
		if(ptr->Next->Next==NULL && ptr->Next->Data==DataDel) 
		{
			temp=ptr->Next;
			free(temp);
			ptr->Next=NULL;
			NumOfNodes--;
			return(TRUE);
		}
	}
	return(FALSE);
}
int Search(int DataSearch) 
{
	struct Node *temp;
	temp=head;
	while(temp->Next!=NULL) 
	{
		if(temp->Data==DataSearch)
			return temp->Data;
		temp=temp->Next;
	}
	if(temp->Next==NULL && temp->Data==DataSearch)
		return temp->Data;
	return(FALSE);
}
void Display(void) 
{
	struct Node *temp = head;
	printf("\nPriority Queue is as Follows:-\n");
	while(temp!=NULL) 
	{
		printf("\t%d",temp->Data);
		temp=temp->Next;
	}
}

