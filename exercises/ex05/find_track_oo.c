/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

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


typedef regex_t Regex;


/* Returns a new Regex that matches the given pattern.
*
* pattern: string regex
* flags: flags passed to regcomp
* returns: new Regex
*/
Regex *make_regex(char *pattern, int flags) {
    regex_t *newReg = malloc(sizeof(regex_t));
    int retVal = regcomp(newReg, pattern, flags);
    if (retVal) {   //if it returns anything but a successful 0
      printf("There was an error compiling the regex.");
      exit(1);
    }
    return newReg;
}

/* Checks whether a regex matches a string.
*
* regex: Regex pointer
* s: string
* returns: 1 if there's a match, 0 otherwise
*/
int regex_match(Regex *regex, char *s) {
    int retVal = regexec(regex, s, 0, NULL, 0);

    if (!retVal) { // if matches
      return 1;
    }

    else if (retVal == REG_NOMATCH) { // if no match
      return 0;
    }

    else {   //error
      char buffer[100];
      regerror(retVal, regex, buffer, sizeof(buffer));
      fprintf(stderr, "Failed to match regex: %s\n", buffer);
      exit(1);
    }
}

/* Frees a Regex.
*
* regex: Regex pointer
*/
void regex_free(Regex *regex) {
    regfree(regex);  // why did we need to make a function when this one's built-in?
}


/* Finds all tracks that match the given pattern.
*
* Prints track number and title.
*/
void find_track_regex(char pattern[])
{
    int i;

    Regex *regex = make_regex(pattern, REG_EXTENDED | REG_NOSUB);

    for (i=0; i<NUM_TRACKS; i++) {
        if (regex_match(regex, tracks[i])) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }

    regex_free(regex);   // why don't we just use built-in regfree(regex)?
}


int main (int argc, char *argv[])
{
    char *pattern = "F.*F.*";
    find_track_regex(pattern);

    return 0;
}
