#include<stdio.h>
#ifndef PLAYER_H
#define PLAYER_H

#define NAME_LEN 30

struct player
{
        int number;
        char first_name[NAME_LEN+1];
        char last_name[NAME_LEN+1];
        struct player *next;
};

//function prototypes
struct player *append_to_list(struct player *roster);
void find_player(struct player *roster);
void printList(struct player *roster);
void clearList(struct player *roster);
struct player* delete_from_list(struct player *roster);
#endif




