#include <math.h>
#include <stdio.h>

int main() {
    int number = 123456789;
    int digit = floor(log10(number)) + 1;
    printf("%d\n", digit);
    int arr[digit];
    int i;
    for (i = digit; i > 0; i--) {
        arr[digit-i] = (int)(number/pow(10,i-1)) % 10;
        printf("%d : %d\n", digit-i, arr[digit-i]);
    }
}
