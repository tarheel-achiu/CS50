#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
   int x = 1;
   int y = 2;
   
   printf("x = %i\n", x);
   printf("y = %i\n", y);
   printf("Swapping...\n");
   // when calling the swap fucntion you must insert a & in front of variable meaning "get me the address of var and pass to function"
   // when you only pass the var name it means to pass a copy of the var
   swap(&x, &y);
   printf("Swapped!\n");
   printf("x = %i\n", x);
   printf("y = %i\n", y);
}

/* incorrect implementation of a swap function. It is operation on copies of a and b. Not the a and b in the main function
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
*/

// correct implementation of the swap function using pointers to the a and b that are used in the main function
// in the parameters of the fuction *var means pass the location of var
void swap(int *a, int *b)
{
    // inside the function *var means go to what ever is at this pointer location. so tmp is assigned to the value that is stored at the location
    int tmp = *a;
    // assign to memory location of pointer a the value of what is at pointer b
    *a = *b;
    // assign to memory location of pointer b the value of tmp
    *b = tmp;
}