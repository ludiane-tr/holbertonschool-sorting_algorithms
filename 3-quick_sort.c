#include "sort.h"

/**
 * partition - ...
 *
 * @array: ...
 * @low: ...
 * @high: ...
 * @size: ...
 *
 * Return: L'indice de la partition (pivot).
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (array[high] != array[i + 1])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i + 1);
}

void quick_sort_rec(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        quick_sort_rec(array, low, pivot - 1, size);
        quick_sort_rec(array, pivot + 1, high, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1, size);
}
