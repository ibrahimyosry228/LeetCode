#include <stdio.h>

int caller;

int search(int* nums, int numsSize, int target)
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
            index = -1;
        }
        caller = 0;
        return index;
    }

    if (target < nums[numsSize / 2])
    {
        //search first half
        search(nums, numsSize / 2, target);
    }
    else if (target >= nums[numsSize / 2])
    {
        //increment index
        index += numsSize / 2;
        //search second half
        search(nums + numsSize / 2, numsSize - numsSize / 2, target);
    }
    caller = 0;
    return index;
}

int main(void)
{
    int array[] = {-1,0,3,5,9,12};
    int index;
    index = search(array, 6, 5);
    printf("%d\n", index);
    int array2[] = {5};
    index = search(array2, 1, 5);
    printf("%d\n", index);
}