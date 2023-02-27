#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int* array = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        array[i] = nums[i] * nums[i];
    }
    for(int i = numsSize - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
    *returnSize = numsSize;
    return array;
}
int main(void)
{
    int size = 4;
    int nums[] = {-5, -3, 2, -1};
    int* sorted;
    sorted = sortedSquares(nums, size, &size);
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",sorted[i]);
    }
    printf("\n");
    free(sorted);
}