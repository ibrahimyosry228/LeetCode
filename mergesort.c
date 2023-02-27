#include <stdio.h>

void merge_sort(int* array, int size);
void swap(int* x, int* y);
void merge(int* array, int size);

int start, mid, end;

int main(void)
{
    int array[] = {400, 361, 196, 144, 49, 25, 4, 4, 16, 36, 36, 49, 64, 81, 100, 144, 289, 289, 324, 324};
    merge_sort(array, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
    return 0;
}

void swap(int* x, int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void merge(int* array, int size)
{
    int i = 0, j = size / 2, k = 0;
    int tmp[size];

    while (i < size / 2 && j < size)
    {
        if (array[i] <= array[j])
        {
            tmp[k] = array[i];
            i++;
        }
        else
        {
            tmp[k] = array[j];
            j++;
        }
        k++;
    }
    while (i < size / 2)
    {
        tmp[k] = array[i];
        i++; k++;
    }
    while (j < size)
    {
        tmp[k] = array[j];
        j++; k++;
    }
    for (k = 0; k < size; k++)
    {
        array[k] = tmp[k];
    }
    return;
}

void merge_sort(int* array, int size)
{
    if (size == 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] > array[1])
        {
            swap(&array[0], &array[1]);
        }
        return;
    }

    merge_sort(array, size / 2);
    merge_sort(array + size / 2, size - size / 2);
    merge(array, size);
    return;
}