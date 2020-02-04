/*  This program documents my experiments with optimization.
    Author: Gracey Wilson
    Sources: Starting example code from Allen Downey's Exercises in C repo.

    1. Compile and look at the assembly language output. Can you find the code that corresponds to this line?
      Line 17 in hello.s corresponds to the line <int x = 5;>.

    2. What happens if you turn on optimization using the flag -O2?
      The assembly code changes a lot, and seems to get rid of the reference to x.

    3. Modify the printf statement to print x, then compile it with and without optimization. What effect does it have when you print x?
      When printing x instead of "Hello World!" and compiling without optimization, the .string reference in line 4 changes from "Hello World!" to "%x". Some lines are also added at line 18. One line changes from "call printf" to "call puts".
      When printing with optimization, changes happen all throughout the assembly code, with some of the most noticeable changes between lines 5-11 and the last few lines. The reference to 5 remains in both. I'm not sure what all the changes mean.

    4. Add <int y = x + 1;> And then print the value of y (but not x). Compile with and without optimization. What happens to x and y?
      Without optimization, the assembly code looks quite similar to the unoptimized code to print x. There are just a few additional lines of code added to the middle.
      With optimization, the y value disappears, like how the x value disappears when that code is optimized (in addition to some other changes).

    5. What conclusions can you draw about how optimization works?
      It seems that optimization doesn't necessarily shorten the length of the assembly code, but can still save time and/or space that it takes the full program to run. To do this, it can implement strategies such as changing the location/format of the variables I originally initialized.
*/

#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%x\n", y);
    return 0;
}
