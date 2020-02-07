/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/* Gracey Wilson's Experiments:
1. The code is intended to create an array of size 5 which contains the integer 42 at each index of the array. If it worked as expected, it would then replace the contents of the array with the value of the index at each index and return these values like so: 0 1 2 3 4
2. When I first compiled the code, I got a warning that the function returns the address of a local variable [Wreturn-local-addr]. This means the code has a pointer which points to a local variable and is attempting to return that location.
3. When I ran the code, it returned 2 locations in memory in hexadecimal, and then a segmentation fault, because the code is trying to read or write to illegal memory locations. In this case, the problem is that the code tries to return pointers to local variables, which are located in the stack and therefore disappear/can be overwritten when the function is finished running.
4. When I commented out the print statements in foo() and bar() and ran it again, the hexadecimal locations were no longer printed, but the segmentation fault remained, because removing the print statements doesn't get rid of the attempts to pass pointers to stack-allocated data.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        // printf("%d\n", array[i]);
    }

    return 0;
}
