/*Author: Shawn A. Clarke
 * Program used to multipply two vectors together 
 * using pointers. It also compares the vectors to
 * see if the are the same */

#include<stdio.h>
//Declares the two functions
int comp_vec(int *v1, int *v2, int n);
void multi_vec(int *v1, int *v2, int *v3, int n);
int main()
{
	//Declares variables 
	int length;
	int i, comp;

	//Prompts and reads the length of the vectors
	printf("Enter the length of the vector\n");
	scanf("%d", &length);

	//Declares the vectors to be used
	int vec1[length];
	int vec2[length];
        int vec3[length];

	//Prompts and reads in the first vector
	printf("Enter the first vector\n");
	for(i=0;i<length;i++)
	{
	  scanf("%d", &vec1[i]);
	}

	//Prompts and reads in the second vector
	printf("Enter the second vector\n");
	for(i=0;i<length;i++)
	{
	  scanf("%d", &vec2[i]);
	}
	
	//Calls the functions to multiply and compare the vectors
	multi_vec(vec1,vec2,vec3,length);
	comp=comp_vec(vec1,vec2,length);
	
	//Displays the multiplication of the vectors
	printf("The multiplication of the vectors is: ");
	for(i=0;i<length;i++)
		printf("%d ",vec3[i]);
	
	//Dissplays whether the vectors are the same or not
	if(comp==0)
	printf("\nThe vectors are not the same\n");
	else
	printf("\nThe vectors are the same\n");
	
return 0;
}

//Function to multiply the vectors
void multi_vec(int *v1, int *v2, int *v3, int n)
{
	//Uses pointers to access the arrays
	int *p, *q;
	q=v2;
	
	//Calculates the multiplication of the vectors
	for(p=v1;p<(v1+n);p++)
	{
		*v3=(*p * *q);
		v3++;
		q++;
	}			
}

//Function to compare the vectors
int comp_vec(int *v1,int *v2, int n)
{
	//Declares pointers and variables for function
	int *i, *j, val=1;
	int zero=0;
	j=v2;
	
	//Determines whether the variables are the same or not
	for(i=v1;i<(v1+n);i++)
	{
		if(*v1!=*v2)
		return zero;
		
	}
	return val;
}		


