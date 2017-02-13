#include<stdio.h>
#include<string.h>
#define STR_LEN 1000


//Initializes the functions
int read_line(char *str, int n);
void merge(char *s3, const char *s1, const char *s2);

int main()
{
	//Initializes the string variables
	char str1[STR_LEN];
	char str2[STR_LEN];
	char str3[STR_LEN+STR_LEN];

	int num1, num2;
	
	//Prompts and reads the two strings
	printf("Enter the first set of characters\n");
	num1=read_line(str1, STR_LEN);
	printf("Enter the second set of characters\n");
	num2=read_line(str2, STR_LEN);
	
	//Calls the merge function to merge the strings
	merge(str3,str1,str2);
	//Prints the resulting string
	printf("New string: %s\n",str3);
	

return 0;
}

//Function to read in the strings
int read_line(char *str, int n)
{
	int ch, i=0;
	while((ch=getchar())!='\n')
	{
		if(i<n)
		{
		   *str++= ch;
		   i++;
		}
	}
	*str='\0';
	return i;
}

//Function which merges the first string with the second string
void merge(char *s3, const char *s1, const char *s2)
{
	while((*s1!='\0')&&(*s2!='\0'))
	{
		*s3++=*s1++;
		*s3++=*s2++;
	}
	while(*s1!='\0')
		*s3++=*s1++;
	while(*s2!='\0')
		*s3++=*s2++;

	  *s3='\0';
}
