/*sets_of_numbers.c, project 4, Program Design
Sets are represented as arrays. The zeroth element of each array
has a special meaning: it indicates the number of elements
in the set. The set elements themselves will be located in array 
elements 1 through N. 
*/

#include <stdio.h>

#define MAX_SET_SIZE 50
#define TRUE 1
#define FALSE 0

void read_set(int a[]);
void print_set(int a[]);
void enter_set(int v, int a[]);
int element_of(int v, int a[]);
void union_set(int a[], int b[], int c[]);
void intersect_set(int a[], int b[], int c[]);
void delete_set(int v, int a[]);
void set_difference(int a[],int b[], int c[]);
void sym_difference(int a[],int b[], int c[]);

/*read in two sets and calcuates the result of various operations on the sets.
*/
int main()
{
   int a[MAX_SET_SIZE+1];
   int b[MAX_SET_SIZE+1];
   int c[MAX_SET_SIZE+1];

   read_set(a);
   read_set(b);
   
   printf("set A:  ");
   print_set(a);

   printf("set B:  ");
   print_set(b);
   
   union_set(a, b, c);
   printf("Union of A and B: ");
   print_set(c);

   intersect_set(a, b, c);
   printf("Intersection of A and B: ");
   print_set(c);

    
   delete_set(5, a);
   printf("Deleting 5 from set A: ");
   print_set(a);

   set_difference(a, b, c);
   printf("Set difference of A and B: ");
   print_set(c);

   sym_difference(a, b, c);
   printf("Symmetric difference of A and B: ");
   print_set(c);
  
   return 0;
}

/*read_set reads integes from standard input and uses enter_set to add them to the set
avoiding repeated entries. */
void read_set(int a[])
{
   a[0]=0; //a[0] is a special elements. It indicates the number of elements in set a.
   
   int value;
   printf("Enter set values, ending with -1.\n");
   scanf("%d", &value);
   while(value != -1){
       enter_set(value, a);
       scanf("%d", &value);
   }
}

/*print_set prints out the content of the set, in the traditional mathemetical notation,
as a list of items separated by commas, surrounded by braces. */
void print_set(int a[0])
{
   int i;
   printf("{");        //the opening brace for the set
   if(a[0]<=0) printf("There is no elements in the set. \n");
   else{
	   //print elements in the set, separated by comma
	   printf("%d", a[1]);
	   for(i = 2; i <= a[0];i++)
		printf(" ,%d", a[i]);
	} 
	
   printf("}\n");        //the closing brace for the set
}

/*enter_set enters an element in the set, avoiding repeated entries.
*/
void enter_set(int v, int a[])
{

   if(a[0] == MAX_SET_SIZE)
	printf("Max set size exceeded\n");
   else if (!element_of(v, a)){  //calls element_of function to determine an element is already in the set
	a[0]++;
     	a[a[0]]=v;
   }
}

/*element_of returns 1(TRUE) or 0(FALSE) depending on whether the element is in the set
*/
int element_of(int v, int a[])
{
   int i;
   for(i = 1; i <= a[0]; i++)
     	if ( a[i] == v) return TRUE;
   return FALSE;
}

/*union_set carries out the union operation on set a and b, storing the result in set c.
*/
void union_set(int a[], int b[], int c[])
{
   int i;
   c[0]=0;  //c[0] is a special elements. It indicates the number of elements in set c.
   
   for(i=1; i<=a[0]; i++)
   	enter_set(a[i], c);

   for(i=1; i<=b[0]; i++)
   	enter_set(b[i], c);

}

/*intersect_set carries out the intersect operation on set a and b, storing the result in set c.
*/
void intersect_set(int a[], int b[], int c[])
{
   int i;
   c[0]=0;  //c[0] is a special elements. It indicates the number of elements in set c.
   for(i=1; i<=a[0]; i++)
	if(element_of(a[i], b))
	   enter_set(a[i], c);


}

/*delete_set carries out the deletion operation on set a*/
void delete_set(int v, int a[])
{
  int i,x;
  for(i=1;i<=a[0];i++)
  {
	if(a[i]==v)
	{
 	   for(x=i;x<=a[0];x++)
	   {
        	a[x]=a[x+1];
	   }//end inner for loop
	   a[0]=a[0]-1;//decrements first set value.
	   a[MAX_SET_SIZE]=0;//makes final value 0
	}//end if
  }//end outer for loop
}//end function

void set_difference(int a[], int b[], int c[])
{
   int i;
   c[0]=0;//Indicates the number of elements in set c

   for(i=1;i<=a[0];i++)
   {
	if(!element_of(a[i],b))
		enter_set(a[i],c);//Determines the set difference
	
   
   }//end for
}//end function

void sym_difference(int a[], int b[], int c[])
{
   int i;
   c[0]=0;//Indicates the number of elements in set c

    for(i=1;i<=a[0];i++)
   {
	//Deteremines the values in A, not in B
	if(!element_of(a[i],b))
		enter_set(a[i],c);

    }//end for
    for(i=1;i<=b[0];i++)
    {
	//Determines the values in B not in A
	if(!element_of(b[i],a))
		enter_set(b[i],c);
    }
} //end function	
  	
