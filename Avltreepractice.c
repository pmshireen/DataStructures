#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
    int ht;
}node;
node * insert(node *,int);
node * delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

void main()
{
	node *root =NULL;
	int check = 1;
	int ch;
	int x,i,n;
	do
	{
		printf("\n1Create\n2.Insert\n3.delete\n4.inorder\n5.preorder\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			       case 1:
				   printf("Enter the no of element to insert\n");
			       scanf("%d",&n);
			       printf("ENter the elements\n");
			       root = NULL;
			       for(i=0;i<n;i++)
					{
					scanf("%d",&x);
					root=insert(root,x);
				    }
				    break;
				    
		            case 2:
		            printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;	
					
					case 3: printf("\nEnter a data:");
							scanf("%d",&x);
							root=delete(root,x);
							break;
							
					case 4:		printf("\n\nInorder sequence:\n");
					        inorder(root);
					        printf("\n");
					        break;
					case 5:  
					        printf("\nPreorder sequence:\n");
					        preorder(root);
					        break;      
					        printf("\n\nInorder sequence:\n");
					        inorder(root);
					        printf("\n");
					        break;	  
							
				    case 6:
					       printf("Exiting !...");
						   check =0;
						   break;
				    default:
					     printf("Enter the valid choice\n");		   			  
		}
		
	}while(check == 1);
}

node * insert(node * T,int x)
{
if(T == NULL)
{
    T = (node*)malloc(sizeof(node));
    T->data=x;
    T->right=NULL;
    T->left=NULL;

}
else 
if(x>T->data)
{
    T->right = insert(T->right,x);
    if(BF(T)==-2)
    if(x>T->right->data)
    T=RR(T);
    else
    T=RL(T);
}
else 
if(x<T->data)
{
    T->left = insert(T->left, x);
    if(BF(T)==2)
    if(x < T->left->data)
    T=LL(T);
    else
    T=LR(T);
}
T->ht = height(T);
return T;
}


node *delete(node * T, int x)
{

    node *p;
    if(T == NULL)
    return NULL;
    else if(x > T->data)
    {
        T->right = delete(T->right, x);
        if(BF(T)>=2)
        if(BF(T->left)>=0)
        T=LL(T);
        else
        T=LR(T);
    }
    else if(x<T->data)
    {
        T->left = delete(T->left, x);
        if(BF(T)>=-2)
        if(BF(T->right)<=0)
        T=RR(T);
        else
        T=RL(T);
    }
    else 
{
    if(T->right != NULL)
    {
    p= T->right;
    if(T->left != NULL)
    p=p->left;
    T->data = p->data;
    T->right = delete(T->right,p->data);
    if(BF(T)  == 2)
    if(BF(T->left)>=0)
    T=LL(T);
    else
    T=LR(T);
    }
    else
    return (T->left);
}
T->ht = height(T);
return T;
}


int height(node *T)
{
	int lh,rh;
	if(T==NULL)
	return 0;
	if(T->left == 0)
	lh = 0;
	else
	lh = 1+T->left->ht;
	if(T->right == 0)
	rh = 0;
	else
	rh = 1+T->right->ht;
	if(lh>rh)
	return lh;
	return rh;
	
}
int BF(node *T)
{
	int lh,rh;
	if(T==NULL)
	return 0;
	if(T->left == 0)
	lh = 0;
	else
	lh = 1+T->left->ht;
	if(T->right == 0)
	rh = 0;
	else
	rh = 1+T->right->ht;
	return (lh-rh);
	
}
node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
 
node * LL(node *T)
{
	T=rotateright(T);
	return(T);
}
 
node * LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
 
node * RL(node *T)
	{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
	}

void preorder(node *T)
{
	if(T!=NULL)
	{
		printf("%d\t",T->data);
		preorder(T->left);
		preorder(T->right);
	}
}
 
void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d)\t",T->data,BF(T));
		inorder(T->right);
	}
}
