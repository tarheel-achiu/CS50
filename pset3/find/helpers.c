/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

//main function to test helper functions
/*bool search(int value, int values[], int n);
void sort(int values[], int n);

int main(void)
{
    int test[3] = {40,41,42};
    
    for (int i = 0; i < 3; ++i)
    {
        printf("%i\n", test[i]);
    }
    printf("\n");
    
    sort(test, 1);
    
    for (int i = 0; i < 3; ++i)
    {
        printf("%i\n", test[i]);
    }
    
    bool answer = search(42, test, 3);
    printf("%s", answer ? "true" : "false");
}
*/

/**
 * Returns true if value is in array of n values, else false.
 * Assumes array is sorted
 */
bool search(int value, int values[], int n)
{
    // Implementation of binary search algorithm
    // return false if n is non-positive
    if (n < 2)
    {
        if (value == values[0])
        {
            return true;
        }
        else
        {
            return false; 
        }
    }
    
    int middle = n/2;
    const int MAX = 65535;
    int new_array[MAX];
    if (value > values[middle])
    {
        int new_size = n - middle - 1;
        for (int i = 0, m = middle + 1; i < new_size; i++, m++)
        {
            new_array[i] = values[m];
        }
        return search(value, new_array, new_size);
    }
    else if (value < values[middle])
    {
        int new_size = n - middle;
        for (int i = 0, m = 0; i < middle + 1; i++, m++)
        {
            new_array[i] = values[m];
        }
        return search(value, new_array, new_size);
    }
    else if (value == values[middle])
    {
        return true;    
    }
    
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implementation of insertion sort algorithm
    // for loop to sort
    // assume values[0] is already sorted
    
    
    for (int i = 0; i < n; i++) 
        {
		    int current_value; /* save the current value */
		    // shift elements of greater value one position ahead
		    for (int previous_value = i - 1; previous_value >= 0; previous_value--)
			{
			    if (values[previous_value + 1] < values[previous_value])
			    {
			        current_value = values[previous_value];
			        values[previous_value] = values[previous_value + 1];
			        values[previous_value + 1] = current_value;
			    }
			    else
			        break;
			}
		
        }
}
