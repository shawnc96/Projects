/*Program dollar.c written by Shawn Clarke
This determines the smallest number of $20
$10, $5 and $1 bills needed for a given US
dollar amount*/

#include<stdio.h>

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
		return 0;
	}
	else
	{

	    //Determines the amount of $20, $10, $5 and $1 bills
	    num20=(dollar/20);

	    /*Subtracts the value of $20bills from the dollar amount
	    to produce a new dollar amount*/
        	 dollar=(dollar-(num20*20));
       	       	num10=(dollar/10);

	    dollar=(dollar-(num10*10));
	    num5=(dollar/5);

      num1=(dollar-(num5*5));

	      printf("Number of $20 bills: %d\n", num20);
        printf("Number of $10 bills: %d\n", num10);
        printf("Number of $5 bills: %d\n", num5);
        printf("Number of $1 bills: %d\n", num1);
	
	}//end else
return 0;
}//end main
