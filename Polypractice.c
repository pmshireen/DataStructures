#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
void readPolynomial(struct node** poly)
{
	int coeff, exp, cont;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	*poly = temp;
	do{
		printf("\n Coeffecient: ");
		scanf("%d", &coeff);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("\nHave more terms? 1 for y and 0 for no: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct node*)malloc(sizeof(struct node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont == 1);	
}
void displayPolynomial(struct node * poly)
{
    printf("\nPolynomial expression is: ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void addPolynomial(struct node **result,struct node * first,struct node * second)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    * result = temp;
    while(first && second)
    {
        if(first->pow >second->pow)
        {
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        }
       else if(second->pow > first->pow)
        {
            temp->coeff =second->coeff;
            temp->pow = second->pow;
            second = second->next;
        }
       else
       {
           temp->coeff = first->coeff + second->coeff;
           temp->pow = first->pow;
           first = first->next;
           second = second->next;

       }
       if(first && second)
       {
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp=temp->next;
            temp->next=NULL;
       } 
    }
    while(first || second)
    {
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp=temp->next;
            temp->next=NULL;

            if(first)
            {
                temp->coeff = first->coeff;
                temp->pow = first->pow;
                first = first->next;
            }
            else if (second)
            {
                temp->coeff =second->coeff;
                temp->pow = second->pow;
                second = second->next;
            }

    }
    
}
int main()
{
	struct node* first = NULL;
	struct node* second = NULL;
	struct node* result = NULL;
    printf("\nEnter the first polynomial\n");
    readPolynomial(&first);
    displayPolynomial(first);
    printf("\nENter the second polynomial\n");
    readPolynomial(&second);
    displayPolynomial(second);
    addPolynomial(&result,first,second);
    displayPolynomial(result);
    return 0;
}
