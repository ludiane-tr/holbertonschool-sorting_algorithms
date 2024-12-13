#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to be partitioned
 * @start: Start index of the partition
 * @end: End index of the partition
 * @size: Total size of the array (for printing purposes)
 * Return: The index of the pivot
 */
int lomuto_partition(int *array, int start, int end, int size)
{
	int key = array[end];
	int key_index = start;
	int i, tmp;

	for (i = start; i < end; i++)

	{
		if (array[i] <= key)
		{
			if (key_index != i)
			{
				tmp = array[key_index];
				array[key_index] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			key_index++;
		}
	}

	if (key_index != end)
	{
		tmp = array[key_index];
		array[key_index] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (key_index);
}

void quicksort_algorithm(int *array, int start, int end, int size);

/**
 * quicksort_algorithm - Recursively sorts the array using Quick Sort
 * @array: The array to be sorted
 * @start: Start index of the current partition
 * @end: End index of the current partition
 * @size: Total size of the array (for printing purposes)
 * Return: Nothing
 */
void quicksort_algorithm(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int key = lomuto_partition(array, start, end, size);

		quicksort_algorithm(array, start, key - 1, size);
		quicksort_algorithm(array, key + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_algorithm(array, 0, size - 1, size);
}
