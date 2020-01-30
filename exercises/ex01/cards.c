/*  This program counts cards.
    Author: Gracey Wilson
    Sources: Originally factored source code from Chapter 1 of Head First C, page 37)
*/

#include <stdio.h>
#include <stdlib.h>

/*  This function figures out how much to add to the running total.
    Input: A three-character array called card_name, and an integer called val.
    Output: An updated value of val.
*/
int determineCard(char card_name[3], int val) {
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      break;
    default:
      val = atoi(card_name);
      if ((val<1) || (val>10)) {
        puts("I don't understand that value!");
        break;
      }
  }
  return val;
}

/*  This function adds the appropriate amount to the running total.
    Input: Our three-character array card_name, int val, and int count
    Output: An updated value of count, our new running total.
*/
int addCard(char card_name[3], int val, int count) {
  if ((val>2) && (val<7)) {
    count++;
  } else if (val == 10) {
    count--;
  }
  return count;
}

/*  This function prints the running total of cards.
    Input: count, the current running total.
    Output: A string displaying "Current count:" and then the running total in integer format.
*/
int printResult(int count) {
  printf("Current count: %i\n", count);
  return 0;
}

/* This function initializes the deck of cards, prompts the user to input a card_name, and then makes calls to 3 other functions which determine the val of the card, add that val to the running total count, and finally prints the running total card count.
  Prompt: string prompt
  Output: A print string containing the running total count.
*/
int main() {
  char card_name[3];
  int count = 0;
  int val = 0;
  while (card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    val = determineCard(card_name, val);
    count = addCard(card_name, val, count);
    printResult(count);
  }
  return 0;
}
