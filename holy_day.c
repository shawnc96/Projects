#include<stdio.h>

int main(void)
{
	int currentDay,D7,dueDay,D;//the variable D represents number of days

	//Prompts and reads the current day
	printf("Enter the day for today (0 for Sunday, 1 for Monday, etc:\n");
	scanf("%d", &currentDay);

	//Aborts program is the current day is outside of the range 0-6
	if((currentDay<0)||(currentDay>6))
		return 0;

	else
	{
		//Prompts and reads number of days til due day
		printf("Enter the number of days to do the work\n");
		scanf("%d", &D);
		D7=D%7;
		dueDay=D7+currentDay;
		
		//Calculates the due day and the new number of days
		switch(dueDay)
		{
			case 0:
			case 7:
				dueDay=1;
				D=D+1;
				break;
			case 5:
			case 12:
				dueDay=1;
				D=D+3;
				break;
			case 6:
			case 13:
				dueDay=1;
				D=D+2;
				break;
			case 8:
				dueDay=1;
				break;
			case 9: 
				dueDay=2;
				break;
			case 10:
				dueDay=3;
				break;
			case 11:			
				dueDay=4;
				break;
		}
		
		//print the number of days along with the due day
		printf("The number of days D is: %d\n", D);
		switch(dueDay)
		{
			case 1:
				printf("The due day is Monday \n");
				break;
			case 2:
				printf("The due day is Tuesday \n");
				break;
			case 3:
				printf("The due day is Wednesday \n");
				break;
			case 4:
				printf("The due day is Thursday \n");
				break;
		}
	}//end else
	
	return 0;
}// end main

