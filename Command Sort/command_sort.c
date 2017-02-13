/*selection_sort.c, project 6, Program Design
 */
//Edited by: Shawn Clarke
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

//Declares the functions to be called
void ascend_sort(int *a, int n);
void descend_sort(int *a, int n);
int *find_largest(int *a, int n);
int *find_smallest(int *a, int n);
void swap(int *p, int*q);
int main(int argc, char *argv[])
{
  
  int i,x;
  int a[8];
  char dsc[]="-d";
  char asc[]="-a";

  for(x=2; x<argc; x++)
	a[x-2]=atoi(argv[x]);

  //Compares the strings and determines how to sort  
  if(strcmp(dsc, argv[1])==0)
	descend_sort(a, N);
  else
  if(strcmp(asc, argv[1])==0)
	ascend_sort(a, N);  
  else
  {
	printf("Invalid option\n");
	return 0;
  }
 //Prints the sorted array
  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}//end main

//Function used the sort the array in ascending order
void ascend_sort(int *a, int n)
{
  //Declares variables for function
  int *large, *last;
  //Initializes last pointer to the last address in the array
  last=a+n-1;
  if (n == 1)
    return;
	  //Calls the find_largest function
	  large=find_largest(a,n);
	  //Calls the swap function
	  swap(last,large);
          //Repeats the selection sort function til all values are sorted
 	  ascend_sort(a, n-1);

}//end ascend_sort

//Function used to sort the array in descending order
void descend_sort(int *a, int n)
{
   int *small, *last;

   last=a+n-1;
   if(n==1)
	return;

		small=find_smallest(a,n);
		swap(last,small);
		descend_sort(a,n-1);
}//end descend_sort

//Function used to determine the smallest value in the array
int *find_smallest(int *a, int n)
{
    int *i;
    int *y;
        y=a;

	for(i=a;i<(a+n);i++)
	{
	   if(*i<*y)
		y=i;
	}
	return y;
}

//Function used to determine the biggest value in the array
int *find_largest(int *a, int n)
{
    int *i;
    int largest=0;
    int *z;
	//Assigns z to the address of largest
	z=&largest;
	//Uses a loop to determine the biggest element
	for(i=a;i<(a+n);i++)
	{
	   if(*i>*z)
		z=i;
	}
	//returns the address of the largest element
	return z;
	
	
}//end find_largest

//Function used to swap the elements
void swap(int *p, int *q)
{
	//Uses temp to temprorarily store variables.
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
	
}//end swap
