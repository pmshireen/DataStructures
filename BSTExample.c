#include<stdio.h>
#include<malloc.h>
struct tree
{
	int data;
	struct tree *rchild;
	struct tree *lchild;
}*t,*temp;
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
struct tree * create(struct tree * ,int);
struct tree * insert(struct tree *,int);
struct tree * delete(struct tree *,int);
struct tree * find(struct tree *,int);
struct tree *findmin(struct tree *);
struct tree * findmax(struct tree *);
int element;
void main()
{
	int ch;
	int check = 1;
	do
	{
		printf("\n1.Create\n2.Insert\n3.Delete\n4.find\n5.findmin\n6.findmax\n7.inorder\n8.preorder\n9.postorder\npreorder\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element\n");
				scanf("%d",&element);
				t = create(t,element);
				//inorder(t);
				break;
			case 2:
			   printf("Enter the element\n");
			   scanf("%d",&element);
			   t = insert(t,element);
			   //inorder(t);
			   break;
			case 3:
			    printf("Enter the element to delete\n");
				scanf("%d",&element);
			    t = delete(t,element);
			    inorder(t);
			    break;
			case 4:
			    printf("Enter the element\n");
				scanf("%d",&element);
				temp=find(t,element);
				if(temp->data==element)
					printf("\nElement found\n");
				else
					printf("\nElement is not found");
				break; 
				case 5:
				temp=findmin(t);
				printf("\nMin element=%d",temp->data);
				break; 
				
				case 6:
				temp=findmax(t);
				printf("\nMax element=%d",temp->data);
				break;
			case 7:
				inorder(t);
				break;
			case 8:
				preorder(t);
				break;
			case 9:
				postorder(t);
		     	break;
		    case 10:
		    	printf("Exiting.....\n");
		    	check = 0;
		    	break;
			default:
			printf("Enter a valid choice\n");
		}
		
		
	}while(check == 1);
}
struct tree * create(struct tree * t ,int element )
{
	if(t == NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->data = element;
		t->lchild =NULL;
		t->rchild = NULL;
		return t;
	}
}
struct tree * find(struct tree *t, int element) 
{
	if(t==NULL)
		return NULL;
	if(element<t->data)
		return(find(t->lchild,element));
	else if(element>t->data)
		return(find(t->rchild,element));
	else
		return t;
}
struct tree *findmin(struct tree * t)
{
	if(t == NULL)
	  return t;
	else if (t->lchild == NULL)
	return t;
	else
	return (findmin(t->lchild)) ; 
	
}
struct tree *findmax(struct tree * t)
{
	if(t == NULL)
	  return t;
	else if (t->rchild == NULL)
	return t;
	else
	return (findmax(t->rchild)) ; 
	
}


struct tree * insert(struct tree * t,int element)
{
	if(t == NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->data = element;
		t->lchild  =NULL;
		t->rchild = NULL;
	}
	else if(element<t->data)
	    t->lchild = insert(t->lchild ,element);
    else if(element>t->data)
        t->rchild = insert(t->rchild ,element);	
	else if(element == t->data)
	    printf("Element already exists\n");
		
}
struct tree * delete(struct tree * t,int element)
{
	 if(t  == NULL)
	  printf("ELement not found\n");
     else if(element<t->data)
	  t->lchild = delete(t->lchild ,element);	
     else if(element>t->data)
      t->rchild = delete(t->rchild ,element);	
	else if(t->lchild && t->rchild)
	{
		temp = findmin(t->rchild);
		t->data =  temp->data;
		t->rchild = delete(t->rchild,temp->data);
		
	}
	else
	{
//		temp=t;
		if(t->lchild==NULL)
			t=t->rchild;
		else if(t->rchild==NULL)
			t=t->lchild;
//		free(temp);
    }
}
void inorder(struct tree * t)

{
	if(t == NULL)
	return ;
	else
	{
		inorder(t->lchild);
		printf("%d\n",t->data);
		inorder(t->rchild);
	}
}
void preorder(struct tree * t)

{
	if(t == NULL)
	return ;
	else
	{
		printf("%d\n",t->data);
		preorder(t->lchild);
		inorder(t->rchild);
	}
}

void postorder(struct tree * t)

{
	if(t == NULL)
	return ;
	else
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%d\n",t->data);
	}
}




