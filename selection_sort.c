/*selection_sort.c, project 6, Program Design
 */
//Edited by: Shawn Clarke
#include <stdio.h>
#define N 10

//Declares the functions to be called
void selection_sort(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int*q);
int main(void)
{
  int i;
  int a[N];
  


  printf("Enter %d numbers to be sorted: ", N);
  for (i=0; i<N; i++)
    {
	scanf("%d",&a[i]);
	
    }
  
  //Calls the selection sort function
  selection_sort(a, N);

  //Prints the sorted array
  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}//end main

//Function used the sort the array
void selection_sort(int *a, int n)
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
 	  selection_sort(a, n-1);

}//end selection sort

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
