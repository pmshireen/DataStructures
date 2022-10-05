#include<stdio.h>
#include<stdlib.h>
# define N 10
int stack[N];
int top = -1;
void create();
void push();
void pop();
void display();
  void  main()
  {
    int res;
    int check = 1;
    printf("Stack implementation using Array\n");
    do{
        printf("\nStack Operations\n1.Create Stack\n2.Push an Element\n3.Pop an Element\n4.Display the stack\n5.Exit\n");
        scanf("%d",&res);
        switch(res){
            case 1:
                printf("Creating a Stack\n");
                create();
                break;
            case 2:
                printf("Pushing an Element\n");
                push();
                break;
            case 3:
                printf("Popping an Element\n");
                pop();
                break;
            case 4:
                printf("Displaying the Stack\n");
                display();
                break;
            case 5:
                printf("Exiting....\n");
                check = 0;
                break;
           default:
                printf("Enter a Valid Option\n");
                break; 
        }
    }while(check == 1);
}
void create()
{
    if(top >= N)
	{
        printf("Stack is Full...\n");
        return;
    }
    int i,n;
      int x;
    printf("Enter the number of elements (Max - %d)\n",N);
    scanf("%d",&n);
    printf("Enter the %d - values\n",n);
    for(i=0;i<n;i++)
	{
        scanf("%d",&x);
        top++;
        stack[top] = x;
       
    }
}

void push()
{
	
    if(top >= N)
	{
        printf("Stack is Full...overflow\n");
        return;
    }
    int x;
    printf("Enter an element to push\n");
    scanf("%d",&x);
    top++;
    stack[top] = x;
}

void pop()
{
	if(top<=0)
	{
		printf("Stack Underflow\n");
		return;
	}
	else
	{
		int val = stack[top];
		top --;
		printf("element deleted is %d\n",val);
	
	}
}
void display()
{
	int i;
	if(top<=0)
	printf("stack is empty\n");
	else
	{
          for(i=top;i>=0;i--)
		  {
		  	printf("%d\t",stack[i]);
		   }		
	}

}














