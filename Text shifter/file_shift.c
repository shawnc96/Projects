/* Author: Shawn A.Clarke
 * Project 8 - file_shift.c
 * Shifts the letters of a string which
 * is stored in a file*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000//sets size of array to 10000
#define SIZE 100//sets size of name to 100

//Declared shift function
void shift(char *message, int shift_amount);
int main()
{
	//Declares variables for shift amount, array and filenames.
	int amt=0;
	char str[MAX];
	char name[SIZE+1];
	char newName[SIZE+1];

	//Prompts and reads the file name from the user
	printf("Enter a file name\n");
	scanf("%s", name);
	
	//Prompts and reads the shift amount from the user
	printf("Enter shift amount\n");
	scanf("%d",&amt);

	//Copies old filename into new variable and adds .sft to it
	strcpy(newName,name);
	strcat(newName, ".sft");


	//Declares the file pointer and opens file for reading
	FILE* fp;
	fp = fopen(name, "r");
	//Checks for error opening file
	if(fp == NULL)
	{
	   printf("Error opening file\n");
	   return 1;
	}

	//Declares pointer for second file and opens it for writing
	FILE* fp1;
	fp1 = fopen(newName, "w");
	
	//Prints the name of the new file
	printf("New file name: %s\n",newName);

	if(fp1==NULL)
	{
	   printf("Error opening file\n");
	   return 1;
	}
	
	
	//Extracts and prints string stored in file
	while(fgets(str, MAX, fp)!=NULL)
	{
	   printf("%s\n", str);
	   //Calls the shift function
	   shift(str,amt);
	   //Adds the new string to the second file
	   fputs(str,fp1);
	}	
       
	

	//Closes file
        fclose(fp);
	fclose(fp1);
	

return 0;
}//end main


//Function used to shift the characters
void shift(char *message, int shift_amount)
{
	char *p;
	char result;
	for(p=message;*p!='\n';p++)
	{
		if((*p>='a')&&(*p<='z'))
		{
		   result= (*p- 'a'+shift_amount);
		   *p=(result)%26 + 'a';
		}
		if((*p>='A')&&(*p<='Z')) 
		{
		   result=(*p-'A'+shift_amount);
		   *p=(result)%26 + 'A';
		}
	}//end for
}//end shift func...  
		


	
