/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

Author: Gracey Wilson
Note: I had a few questions answered by NINJA Prava, and worked with William Derksen and Shirin Kuppusamy for portions of this HW!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Determines whether a string matches a pattern according to the definition of regular expressions.
// Returns 0 if there's an error (if the string is not contained in the pattern) and return 1 if the pattern does exist.
int match(const char *string, char *pattern)
{
    int status;
    regex_t re;

    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
      printf("Did not compile - there was an error\n"); // I imagine I could use regerror() here but I couldn't figure it out in the documentation. Is that a requirement?
      return(0);      /* report error */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
      if (status !=1) {
        printf("Did not execute - there was an error\n"); // I imagine I could use regerror() here but I couldn't figure it out in the documentation. Is that a requirement?
        exit(1);
      }
      return(0);      /* report error */
    }
    return(1);
}

// Finds all tracks that match the given pattern.
// Prints track number and title.
void find_track_regex(char pattern[])
{
  int i;
  for (i=0; i<NUM_TRACKS; i++) {
      if ((match(tracks[i], pattern)) == 1) {     // if match() returns 1 for that line,
          printf("Track %i: '%s'\n", i, tracks[i]); //print that line
      }
  }
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
