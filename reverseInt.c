#include <stdio.h>
#include <stdlib.h>

int main()
{
    int target = 1234;
    int divider = 10;
    int result;
    while (target != 0)
    {
        int lastNumber = target % divider;
        result = result * 10 + lastNumber;
        target /= divider;
    }
    printf("%i\n", result);
}