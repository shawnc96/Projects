#include<stdio.h>
#include<math.h>

#define Volts 10
#define C .00005
#define R 3000
int main (void)
{

	//Declaring variables to be used
	double voltage=0;;
	double t;
	double incr;
	double c=R*C;
	incr=(0.066667);//sets the increment at 1/15
	
	printf("time\t\tvoltage\n");//print statement to show time and voltage

	for (t=0.0; t<=1.01;)//for loop used to calculate the voltage
	{
		voltage=Volts*(1-(exp(-t/c)));//calculates the voltage
		printf("%.2f \t\t" ,t);
		printf( "%.2f \n", voltage);//prints the time and voltage
		t+=incr;//increments t at the end of the loop
	}//end for

return 0;
}//end main
