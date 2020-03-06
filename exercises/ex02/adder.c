/*
Author: Gracey Wilson
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addUp(int *s, int length) {
  /*
    Input: a pointer to an array of ints, and an integer which is the size of that array.
    Output: an integer, the total of all the contents of the int array added up.
  */
  int total;
  for (int i=0; i<length; i++) {
    printf("%i\n", s[i]);
    total += s[i];
  }
  printf("%i\n", total);
  return total;
}


int main() {
  /*
    This function prompts a user to input numbers. It converts each input to int format and saves it to an array called nums. Then it calls addUp() which adds the numbers all up. Then it prints the total.
  */
  char input[5];
  int nums[5];
  int index = 0;
  printf("\n Input an integer: ");
  while (fgets(input, 5, stdin) != NULL) {  // Typing Ctrl-D will return NULL and end the loop
    if (index > 4) {
      printf("Please enter a number with 5 digits or less. \n"); // Error if input size too big
      break;
    }
    printf("Input an integer: ");
    nums[index] = atoi(input);  // Converts input from strings to ints
    printf("%i\n", index);
    index++;
  }

  // for (int i=0; i<index; i++) {
  //
  //   printf("%i\n", nums[i]);
  // }
  int total = addUp(nums, index);
  printf("Your total is: %i\n", total);
  // optional: error if sum exceeds largest int that can be repped
  return 0;
}
