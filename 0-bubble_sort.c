#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 *
 * @array: Array.
 * @size: Size of array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				flag = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		if (!flag)
		{
			return;
		}
	}
}
