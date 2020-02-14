#include <stdio.h>
#include <stdlib.h>

int operate(int x, int y, char operator, int *result) {
    if (operator == '+') {
        *result = x + y;
        return 0;
    }
    if (operator == '*') {
        *result = x * y;
        return 0;
    }
    return -1;
}

int main() {
  int *p = malloc(sizeof(int));
  int ans = operate(2,3,'+',p);
  printf("%i\n", ans);
  return 0;
}
