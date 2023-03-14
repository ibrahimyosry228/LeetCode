#include <stdio.h>
#include <stdlib.h>

int binary_search_i(int* arr, int size, int target);
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main ()
{
    int nums[] = {2, 5, 9, 15, 23, 24, 28, 33, 36, 40, 45, 48, 56, 60, 67, 80, 80, 80, 80, 99};
    int ret = 0, i;
    int* ptr = &ret;
    int* pos = searchRange(nums, 20, 80, ptr);
    printf("[ ");
    for(i = 0; i < *ptr; i++)
    {
        printf("%d ", pos[i]);
    }
    printf("]\n");
    free(pos);
    return 0;
}

int binary_search_i(int* arr, int size, int target)
{
    int l = 0, r = size - 1;
    int m = l + (r - l) / 2;
    while (l <= r)
    {
        if (target == arr[m])
        {
            return m;
        }
        else if (target < arr[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        m = l + (r - l) / 2;
    }
    return -1;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int max, min;
    *returnSize = 2;
    int* ret = (int*)malloc(2 * sizeof(int));
    int x = binary_search_i(nums, numsSize, target);
    if(x == -1)
    {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    min = x;
    max = x;
    while (min >= 0 && target == nums[min])
    {
        min--;
    }
    min++;
    
    while (max < numsSize && target == nums[max])
    {
        max++;
    }
    max--;
    ret[0] = min;
    ret[1] = max;
    return ret;
}