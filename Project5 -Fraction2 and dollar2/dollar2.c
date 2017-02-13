/*Program dollar.c written by Shawn Clarke
This determines the smallest number of $20
$10, $5 and $1 bills needed for a given US
dollar amount*/

#include<stdio.h>

//Declares the function pay
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{

    //Declaring variables to represent the dollar values.
    int dollar, num20, num10, num5, num1;	

    //Prompt and reads in US dollar amount
    printf("Enter a US dollar amount");
    scanf("%d",&dollar);
	
	//Aborts program is value is too small/large
	if((dollar<0)||(dollar>1000000000))
	{
		printf("Invalid amount. Must be between 0 and 1000000000");
		return 0;
	}
	else
	{
		//Calls the function pay_amount to 
		pay_amount(dollar, &num20, &num10,&num5, &num1);	
		
		//Prints the number of 20s, 10s, 5s and 1s
		printf("Number of $20 bills: %d\n", num20);
        	printf("Number of $10 bills: %d\n", num10);
        	printf("Number of $5 bills: %d\n", num5);
        	printf("Number of $1 bills: %d\n", num1);
	
	}//end else
return 0;
}//end main


void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	//Determines the number of 20s, 10s, 5s and 1s using pointers
	*twenties=dollars/20;
	dollars=dollars%20;
	*tens=dollars/10;
	dollars=dollars%10;
	*fives=dollars/5;
	dollars=dollars%5;
	*ones=dollars;
}

