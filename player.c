#include<stdio.h>
#include<stdlib.h>
#include "player.h"
#include "readline.h"

struct player *append_to_list(struct player *roster){

	struct player *q;
        struct player *new;
        struct player *temp;
        int i=0;

        new=malloc(sizeof(struct player));
        if(new==NULL)
        {
           printf("Malloc failed!\n");
           return roster;
        }

	printf("Enter the number for the player\n");
        scanf("%d",&new->number);

        for(q=roster;q!=NULL;q=q->next)
        {
           if(q->number==new->number)
           {
                printf("Player exists already!!\n");
                i++;
                break;
           }
        }


        if(i==0)
        {
        printf("Enter the player's last name\n");
        read_line(new->last_name,NAME_LEN);
        printf("Enter the player's first name\n");
        read_line(new->first_name,NAME_LEN);

        new->next=NULL;


        if(roster==NULL)
        {
           roster=new;
           return roster;
        }
        else
        {
           temp=roster;
           while(temp->next!=NULL)
           {
                temp=temp->next;
           }

           temp->next=new;
           return roster;
        }//end else
        }//end if(i==0)
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
           printf("%s\t%s\n",p->first_name,p->last_name);
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

