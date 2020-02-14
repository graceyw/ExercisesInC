/*
Gracey Wilson
probably want to use fgets, strlen and atoi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(int *s) {
  int num = atoi(s);
  return 0;
}

int main() {
  char input[];
  printf("Input an integer: ");
  fgets(input, 3, stdin);
  //make a pointer to the string user inputted
  // convert(int *s);
  // add them all up
  // error if sum exceeds largest int that can be repped
  return 0;
}
