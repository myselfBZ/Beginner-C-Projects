#include <stdio.h>
#include <stdlib.h>

int *towSum(int *array, int *target, int *length);

int main()
{
    int array[] = {1, 3, 4, 5};
    int target = 8;
    int length = sizeof(array) / sizeof(array[0]);
    int *result = towSum(array, &target, &length);
    if (result == NULL)
    {
        printf("No numbers to add up!!!\n");
    }
    else
    {
        printf("%i, %i\n", result[0], result[1]);
    }
    free(result);
    return 0;
}

int *towSum(int *array, int *target, int *length)
{
    int len = *length;
    for (int i = 0; i < 4; i++)
    {
        int compliment = *target - array[i];
        for (int j = 0; j < len; j++)
        {
            if (compliment == array[j])
            {
                int *indices;
                indices = (int *)malloc(2 * sizeof(int));
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }

    return NULL;
}