// http://valgrind.org/docs/manual/quicl-start.html#quick-start.prepare.

#include <stdlib.h>

void f(void)
{
    // malloc stores memory in the heap
    int *x = malloc(10 * sizeof(int));
    // index 10 does not exist, swith to index 9
    x[9] = 0;
    // free allocated memory
    free(x);
}

int main(void)
{
    f();
    return 0;
}

// to use valgrind:
// $ valgrind ./memory

// issues that can result from memory issues
// stack overflow
// heap overflow
// buffer overflow