/*
Author: Gracey Wilson
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convertToInt(char *s) {
  for (int i=0; i<strlen(s); i++) {
    s[i] = atoi(s[i]);
    // total += atoi(s[i]); //uncomment and add total as an input for this to work
  }
  return s;
}

int addUp(char *s) {
  int total;
  for (int i=0; i<strlen(s); i++) {
    total += s[i];
  }
  return total;
}

int main() {
  char input[]; //how do i know how big to make it? malloc?
  char *s = input; //makes a point to where the user's input will be stored
  int total;
  // printf("%i\n", strlen(s));
  while (input != ctrl-D) {
    printf("Input an integer: ");
    fgets(input, 5, stdin);
    //error if input greater than permitted size
  }
  convertToInt(s);  //converts the contents of s from strings to ints
  total = addUp(s);
  printf("%i\n", total);
  // optional: error if sum exceeds largest int that can be repped
  return 0;
}
