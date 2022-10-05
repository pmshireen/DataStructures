#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *right ,*left;
}*t,*temp;
int element;
struct node *create(struct node *,int );
struct node *insert(struct node *,int );
struct node *delete(struct node *,int);
struct node * findmin(struct node *);
struct node * findmax(struct node *);
struct node *search(struct node *,int );
void inorder(struct node*);
void preorder(struct node *);
void postorder(struct node *);

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
				temp = search(t,element);
				if(temp->data==element)
					printf("\nElement %d is at %d",element,temp);
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

struct node *create(struct node * t,int element)
{
    if(t == NULL)
    {
        t = (struct node*)malloc (sizeof(struct node));
        t->data = element;
        t->right = NULL;
        t->left = NULL;
    }
}
struct node * search(struct node * t,int element )
{
	if(t==NULL)
		return NULL;
	if(element<t->data)
		return(search(t->left,element));
	else if(element>t->data)
		return(search(t->right,element));
	else
		return t;
}
struct node *insert(struct node * t,int element)

{
    if(t == NULL)
    {
        t = (struct node*)malloc (sizeof(struct node));
        t->data = element;
        t->right = NULL;
        t->left = NULL;
    }
    else if(element < t->data)
    t->left = insert(t->left,element);
    else if(element > t->data)
    t->right = insert(t->right,element);
    else if(element == t->data)
    {
        printf("Element already present\n");
    }
}
struct node * delete(struct node *t ,int element)
{
    if(t == NULL)
    printf("element not found\n");
    else if(element < t->data)
    t->left = delete(t->left,element);
    else if(element > t->data)
    t->right = delete(t->right,element);
    else if(t->left && t->right)
	{
		temp = findmin(t->right);
		t->data =  temp->data;
		t->right = delete(t->right,temp->data);
		
	}
	else
	{
//		temp=t;
		if(t->left==NULL)
			t=t->right;
		else if(t->right==NULL)
			t=t->left;
//		free(temp)
    }
}
struct node * findmin(struct node *t)
{
    if(t == NULL)
    return t;
    else if (t->left == NULL)
    return t;
    else
    return (findmin(t->left));
}
struct node * findmax(struct node *t)
{
    if(t == NULL)
    return t;
    else if (t->right == NULL)
    return t;
    else
    return (findmax(t->right));
}
void inorder(struct node * t)
{
    if(t == NULL)
    return ;
    else
    {
        inorder(t->left);
        printf("%d\t",t->data);
        inorder(t->right);

    }

}
void preorder(struct node * t)
{
    if(t == NULL)
    return ;
    else
    {
        printf("%d\t",t->data);
        preorder(t->left);
        preorder(t->right);
        
    }

}
void postorder(struct node * t)
{
    if(t == NULL)
    return ;
    else
    {
        
        postorder(t->left);
        postorder(t->right);
        printf("%d\t",t->data);
        
    }

}
