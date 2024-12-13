#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending
 * @array: you swap two elements
 * @size: the size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, step;
	size_t case_best;
	int tempory;

	for (step = 0 ; step < size - 1 ; step++)
	{
		case_best = step;

		for (i = step + 1 ; i < size ; i++)
		{
			if (array[i] < array[case_best])
				case_best = i;
		}
		if (case_best != step)
		{
			tempory = array[step];
			array[step] = array[case_best];
			array[case_best] = tempory;
			print_array(array, size);
		}
	}
}
