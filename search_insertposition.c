#include <stdio.h>

int caller;

int searchInsert(int* nums, int numsSize, int target)
{
    static int index;
    if (caller == 0)
    {
        index = 0;
        caller = 1;
    }

    if (numsSize == 1)
    {
        if (*nums != target)
        {
            index ++;
            if (target < nums[0])
            {
                index--;
            }
        }
        caller = 0;
        return index;
    }

    if (target < nums[numsSize / 2])          //search first half
    {
        searchInsert(nums, numsSize / 2, target);
    }
    else if (target >= nums[numsSize / 2])    //search second half
    {
        index += numsSize / 2;  //increment index
        searchInsert(nums + numsSize / 2, numsSize - numsSize / 2, target);
    }
    caller = 0;
    return index;
}

int main(void)
{
    int array[] = {1, 3, 5, 6};
    int index;
    index = searchInsert(array, 4, 5);
    printf("%d\n", index);
    //int array2[] = {5};
    index = searchInsert(array, 4, 7);
    printf("%d\n", index);
}