/* Author: Shawn Clarke
 * sort_commands.c:sorts commands entered by a user
 * using a qsort function*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declares the compare function to be used in sqort
int compare(const void *p, const void *q);
int main(int argc, char *argv[])
{
	//Calls the qsort function to sort the string
  	qsort(argv,argc,sizeof(char *),compare);

	int i;
	//Prints the sorted sentence
	for(i=1;i<argc;i++)
	{
	   printf("%s ",argv[i]);
	}
	printf("\n");
	return 0;

}
//end main

//Function used to compare strings
int compare(const void *p, const void *q)
{
	return strcmp(*(char**)p,*(char**)q);
}

