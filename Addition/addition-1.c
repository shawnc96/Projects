#include<stdio.h>

int add(int n, int m);

int main(void)
{
	int x, y, sum;//Variables declared to hold values and sum

	//Prompts and reads in the two numbers
	printf("Enter the first number\n");
	scanf("%d", &x);
	printf("Enter the second number\n");
	scanf("%d", &y);

	/*Initializes sum to 0 and calls the addition funcction
	to calculate the sum*/
	sum=0;
	sum=add(x,y);
	
	//Prints the sum of the numbers
	printf("The sum of the numbers is %d", sum);

	return 0;
}//end main

int add(int n, int m)
{
	int val;//Declariables variable to be returned
	//Calculates the sum using a recursive function
	if(n==0)
	return m;
	if(m==0)
	return n;
	else
	if(m>0)	
	return val= add(++n, --m);
	else if(m<0)
	return val= add(--n, ++m);
	return 0;	
}//end function add	
