#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Defines a structure box and it's elements
struct box
{
   float length;
   float width;
   float height;
   float volume;
   float weight;
};

void print(struct box hold[],int nb);
void selection_sort(struct box myBoxes[], int n);

int main(void)
{
   //Declares variables to be used throughout main
   float len=0.0,wid=0.0,hei=0.0,wei=0.0;
   int numBox=0;  
   struct box boxes[MAX];
   int x=0;
   int y;
   float vol;
 
   //Initializes the first file pointer and opens the file for reading
   FILE *fp;
   fp=fopen("boxes.txt","r");
   if(fp==NULL)
   {
	printf("Error opening file\n");
	return 1;
   }


   //Reads in the variables from the boxes.txt file
   while(4)
   {
	
	if(fscanf(fp,"%f,%f,%f,%f",&len,&wid,&hei,&wei)==4)
	{
  	   boxes[x].length=len;
	   boxes[x].width=wid;
	   boxes[x].height=hei;
	   boxes[x].weight=wei;
	   vol=(len*wid*hei);
	   boxes[x].volume=vol;
 	   
	   x++;
	   numBox++;
	}

	else
	   break;
	   
	

  }//end while..
	//Closes file
	fclose(fp);
    //Calls the print function to print the elements of the boxes structure
    print(boxes,numBox);
    //Calls the selection sort function to sort the boxes
    selection_sort(boxes,numBox); 
    //Prints the sorted boxes
    printf("\n\n\nSorted Boxes:\n");
    print(boxes,numBox);
  
	//Initializes 2nd file pointer and open second file for writing
	FILE *fp1;
	fp1=fopen("sorted_boxes.txt","w");

    if(fp1==NULL)
    {
	printf("Error opening file\n");
	return 1;
    } 
  
    //Adds the elemnets of the boxes structure to the sorted_boxes.txt file
    for(y=0;y<numBox;y++)
    {
	fprintf(fp1,"%f, %f, %f, %f, %f\n",boxes[y].length,boxes[y].width,boxes[y].height,boxes[y].volume,boxes[y].weight);
    }

    ///Closes file 2
    fclose(fp1);

return 0;
}//end main

//Function print is used to print the elements of a box structure
void print(struct box hold[],int nb)
{
   int i;
   printf("#\tLength\t\tWidth\t\tHeight\t\tVolume\t\tWeight\n");
   for(i=0;i<nb;i++)
   {
	printf("%d\t%f\t%f\t%f\t%f\t%f",i,hold[i].length,hold[i].width,hold[i].height,hold[i].volume,hold[i].weight);
   }

}//end print...

//Function used to sort the elements of the boxes sturcture in asending order
void selection_sort(struct box myBoxes[], int n)
{
   int j, large=0;
   struct box temp;
   
   if(n==1)
   return;

   for(j=0;j<n;j++)
   {
	if(myBoxes[j].volume>myBoxes[large].volume)	
	large=j;
   }

   if(large<n-1)
   {
	temp=myBoxes[large];
	myBoxes[large]=myBoxes[n-1];
	myBoxes[n-1]=temp;
   }

   selection_sort(myBoxes, n-1);
}//end selection...
