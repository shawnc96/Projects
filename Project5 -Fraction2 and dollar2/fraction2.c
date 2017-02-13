/*Program name: fraction.c
 * by: Shawn Clarke
 *Description: asks the user to two fractions separated by an operator and calculates the result. 
*/

#include<stdio.h>

int find_gcd(int m, int n);
void reduce(int numerator, int denominator, int *reduced_numerator, 
		int *reduced_denominator);
int main(void)
{
	char opr;//declares variable for operator
	int nume1, nume2, dem1, dem2, nume3, dem3;//variables forfractions
	int redNume, redDem;
	//Prompts and reads the fractions and operator
	printf("Enter 2 frations seperated by an operator\n");
	scanf("%d/%d %c %d/%d",&nume1,&dem1,&opr,&nume2,&dem2);

		switch(opr)//carries out operations based on the operator
		{
			case '*'://multiplies the fractions
				nume3=nume1*nume2;
				dem3=dem1*dem2;
				printf("The product is %d/%d\n",nume3,dem3);
				//Calls the reduce function to reduce fraction
				reduce(nume3, dem3, &redNume,& redDem);
				break;
			case '/'://divides the fractions
				nume3=nume1*dem2;
				dem3=dem1*nume2;
				printf("The quotient is %d/%d\n",nume3,dem3);
				//Calls the reduce function to reduce fraction
				reduce(nume3, dem3, &redNume,& redDem);	
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
				printf("The sum is %d/%d\n",nume3,dem3);	
				reduce(nume3,dem3,&redNume,&redDem);
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
				printf("The difference is %d/%d\n",nume3,dem3);
				reduce(nume3,dem3,&redNume,&redDem);
				break;
			default:
				printf("Unrecognized operator: %c\n", opr);
				return 0;
		}//end switch
	
	
	//Prints the reduced fraction
	printf("The reduced fraction is: %d/%d",redNume, redDem);
	return 0;
}//end main

//Finds the greatest common diviser 
int find_gcd(int m, int n)
{
	if(n==0) 
	return m;
	return find_gcd(n, m%n);
}
//Reduces the fraction using the GCD
void reduce(int numerator, int denominator, int *reduced_numerator, 
		int *reduced_denominator)
{
	int gcd=find_gcd(numerator, denominator);
	*reduced_numerator=numerator/gcd;
	*reduced_denominator=denominator/gcd;
}	
