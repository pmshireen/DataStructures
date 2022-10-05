#include <stdio.h>
void main() //# Missed () braces
{
int rem;
int n; // n not declared
int i;
int count = 0;

printf("Enter the number\n");
scanf("%d",&n);
int num = n; // to have a copy
// we do not know how many time to run loop so we cant use for loop
// we have to use while loop
// and condition has to be when number n is not equal to zero

/*for(i=0;i<n;i++)
{
    rem = n % 2;  
    count ++;
}*/
if(n == 0)
{
    count = 1; // Since 0 is a single digit binary number
}
while(n > 0){ // here we have to divide value of n by 2 so as to get binary digits
	n = n / 2; // n divide by 2 and update the same value so that loop can end
	count++; // for each division we get a remainder and that is a binary number
}
printf("the number of digits in a %d is %d",num,count); // the copy is used to print n here

}

