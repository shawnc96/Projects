#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "player.h"
#include "readline.h"

//Function to append a node to list
struct player *append_to_list(struct player *roster)
{

	struct player *q;
        struct player *new;
	struct player *cur, *prev;
        int i=0;

        new=malloc(sizeof(struct player));
        if(new==NULL)
        {
           printf("Malloc failed!\n");
           return roster;
        }

	//Promts and reads a number from the user
	printf("Enter the number for the player\n");
        scanf("%d",&new->number);

	//Determines if number already exists
	for(q=roster;q!=NULL;q=q->next)
	{
           if(q->number==new->number)
           {   
                printf("Player exists already!!\n");
		free(new);
                i++;
                return roster;
    	   }
	}

	//Asks the user to enter the player's name
	if(i==0)
	{
	   printf("Enter the player's last name\n");
	   read_line(new->last_name,NAME_LEN);
	   printf("Enter the player's first name\n");
	   read_line(new->first_name,NAME_LEN);

	//Sorts players in order of last name then first
        for(cur=roster,prev=NULL;(cur!=NULL)&&(
        (strcmp(new->last_name,cur->last_name)>0)||(
	(strcmp(new->last_name,cur->last_name)==0)&&
	(strcmp(new->first_name,cur->last_name)<0)));
	prev = cur, cur=cur->next);
	
      
	if(prev==NULL)
	{
	   new->next=roster;
	   roster=new;
	   return roster;
	}

	prev->next=new;
	new->next=cur;
}
return roster;

}//end append


void find_player(struct player *roster)
{
        struct player *p;
        int num;

        printf("Enter the player's number\n");
        scanf("%d",&num);

        for(p=roster;p!=NULL;p=p->next)
        {
           if(p->number==num)
           {
                printf("%s, %s",p->last_name, p->first_name);
                return;
           }
        }

        printf("Player not found!\n");
        return;
}//end find player

void printList(struct player *roster)
{
        struct player *p;
        printf("Number\tLast\tFirst\n");

        for(p=roster;p!=NULL;p=p->next)
        {
           printf("%d\t",p->number);
           printf("%s\t%s\n",p->last_name,p->first_name);
        }//end for

}//end print
void clearList(struct player *roster)
{

        struct player *p;
        while(roster!=NULL)
        {
           p=roster;
           roster=roster->next;
           if(p!=NULL)
                free(p);
        }
return;
}

struct player* delete_from_list(struct player *roster)
{
	struct player *cur;
	struct player *pre;
	int num;

	printf("Enter the player number to be deleted\n");
	scanf("%d",&num);

	for(cur=roster,pre=NULL;cur!=NULL&&cur->number!=num;pre=cur,
	    cur=cur->next);

	if(cur==NULL)
	   return roster;
	if(pre==NULL)
	   roster=roster->next;
	else
	{
	   pre->next=cur->next;
	   free(cur);
	}

	return roster;
}
