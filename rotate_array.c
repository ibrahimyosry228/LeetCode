#include <stdio.h>

void swap(int* x, int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void mirror(int* array, int size)
{
    for (int j = 0; j < size / 2; j++)
    {
        swap(&array[j], &array[size - 1 - j]);
    }
}

void rotate(int* nums, int numsSize, int k)
{
    while (k > numsSize)
        k -= numsSize;
    mirror(nums, numsSize - k);
    mirror(nums + numsSize - k, k);
    mirror(nums, numsSize);
}
int main(void)
{
    int array[] = {400, 361, 196, 144, 49, 25, 4, 4, 16, 36, 36, 49, 64, 81, 100, 144, 289, 289, 324, 324};
    rotate(array, 20, 5);
        for (int i = 0; i < 20; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
    return 0;
}