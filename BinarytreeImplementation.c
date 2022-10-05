#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL;
struct node * create();
void PreOrder(struct node *root);
void InOrder(struct node *root);
void PostOrder(struct node *root);
void main()
{
	int ch;
	int check =1;
	do
	{
		printf("\n Binary tree operations\n");
		printf("\n1.create\n2.Inorder\n3.Preorder\n4.Postorder\n");
		printf("ENter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				   root =  create();
				   printf("binary tree created successfully\n");
				   break;
			
			case 2:InOrder(root);
			       break;
			case 3:PreOrder(root);
			       break;       
			case 4:PostOrder(root);
			       break;	 
			case 5:
			       check = 0;
				   printf("Exiting!....\n");
				   break;	   
		    default:
			      printf("Enter the valid choice\n");		            
			    	
		}
	}while(check == 1);
}
struct node * create()
{
    int x;
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter any data to insert in the tree(-1 for no node)\n");
    scanf("%d",&x);
    if(x == -1)
	{
        return NULL;
    }
    newNode->data = x;
    printf("Enter the left child of %d\n",x);
    newNode->left = create();
    printf("Enter the right child of %d\n",x);
    newNode->right = create();
    return newNode;
}

void PreOrder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct node *root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(struct node *root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}



