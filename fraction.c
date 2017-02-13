/*Program name: fraction.c
 * by: Shawn Clarke
 *Description: asks the user to two fractions separated by an operator and calculates the result. 
*/

#include<stdio.h>

int main(void)
{
	char opr;//declares variable for operator
	int nume1, nume2, dem1, dem2, nume3, dem3;//variables forfractions
	
	//Prompts and reads the fractions and operator
	printf("Enter 2 frations seperated by an operator\n");
	scanf("%d/%d %c %d/%d",&nume1,&dem1,&opr,&nume2,&dem2);

		switch(opr)//carries out operations based on the operator
		{
			case '*'://multiplies the fractions
				nume3=nume1*nume2;
				dem3=dem1*dem2;
				break;
			case '/'://divides the fractions
				nume3=nume1*dem2;
				dem3=dem1*nume2;
				break;
			case '+'://adds the fractions
				if(dem1==dem2)
				dem3=dem1;
				else
				{
				dem3=dem1*dem2;
				nume1*=dem2;
				nume2*=dem1;
				}
				nume3=nume1+nume2;
				break;
			case '-'://subtracts the fractions
				if(dem1==dem2) 
				dem3=dem1;
				else
				{
				dem3=dem1*dem2;
				nume1*=dem2;
				nume2*=dem1;
				}
				nume3=nume1-nume2;
				break;
		}//end switch
	//Prints the newly calculated fractions
	printf("The difference is: %d/%d",nume3, dem3);
	return 0;
}//end main
	
