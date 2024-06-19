#include <stdio.h>
#include <stdlib.h>

void reverseArray(int length, int *array)
{
    int start = 0;
    length = length - 1;
    while (start < length)
    {
        int first = array[start];
        array[start] = array[length];
        array[length] = first;
        start++;
        length--;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    reverseArray(length, array);
    for (int i = 0; i < length; i++)
    {
        printf("%i\n", array[i]);
    }
    return 0;
}