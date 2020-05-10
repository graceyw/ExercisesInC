/* Gracey Wilson HW 6: I changed some index calls, commented out lines doing illegal things, and made sure to free everything that was allocated. Valgrind ran with 0 memory leaks in the end! Note: Awesome NINJA Prava helped me by answering my questions about what Valgrind was trying to tell me.

Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {  //should prob take void *p because it only frees ints
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{
    int never_allocated;
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int array1[100];
    int *array2 = malloc(100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    read_element(array1, 2);  //when index was -1 it was out of bounds, but didn't show up in valgrind
    read_element(array1, 99);

    // but it does bounds-check dynamic arrays
    read_element(array2, 2);  //when index was -1 it showed up in valgrind
    read_element(array2, 99);

    // and it catches use after free
    // free(use_after_free);  //commented out so that we can change the value of use_after_free
    *use_after_free = 17;
    free(use_after_free);

    // never_free is definitely lost
    *never_free = 17;
    free(never_free);

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // free_anything(&never_allocated);

    free(free_twice);
    free(array2);
    // free(free_twice);

    return 0;
}
