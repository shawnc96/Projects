//Author: Shawn Clarke
//Designed to store roster info for players

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"
#include "player.h"
#define NAME_LEN 30


/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct player *team_roster = NULL;  
  printf("Operation Code: a for appending to the roster, f for finding a player"
	  ", p for printing the roster; q for quit.\n");
  for (;;) {
    printf("Enter operation code:\n ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': team_roster = append_to_list(team_roster);
                break;
      case 'f': find_player(team_roster);
                break;
      case 'p': printList(team_roster);
                break;
      case 'd': team_roster = delete_from_list(team_roster);
		break;
      case 'q': clearList(team_roster);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}//end main

