#include <stdbool.h>
#include <stdio.h>

int bad, y;

bool isBadVersion(int version)
{
    if (bad <= version)
        return true;
    else
        return false;
}

volatile int x = 0;
volatile int start = 1, end, mid;

int firstBadVersion(int n) 
{
    end = n;
    mid = start + (end - start) / 2;

    if (isBadVersion(n) && !isBadVersion(n - 1))
    {
        x = n;
    }

    else if (isBadVersion(mid))           //first bad version before this one (search first half)
    {
        end = mid;
        firstBadVersion(end);
    }
    else                                  // first bad version after this one (search second half)
    {
        start = mid;
        firstBadVersion(end);
    }
    start = 1;
    return x;
}

int main(void)
{
    bad = 4;
    y = firstBadVersion(5);
    printf("first bad version is: %d\n", y);

    bad = 1;
    y = firstBadVersion(2);
    printf("first bad version is: %d\n", y);
    return 0;
}