#include "sort.h"

/**
* swap - Function
* @a: number in position i
* @b: NUmber in position j
* @size: size of array
* @array: array to sort.
*/
void swap(int *a, int *b, size_t size, int *array)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
* separation - Separating function
*
* @array: this is the array to sort
* @s: Number to left
* @last: number to right
* @size: size of array
*
* Return: index of piv
*/
int separation(int *array, int s, int last, size_t size)
{
	int piv = array[last], i = 0, j = 0;

	i = s - 1;

	for (j = s; j <= last; j++)
	{
		if (array[j] < piv)
		{
			i++;
			if (i != j && i >= 0)
			{
				swap(&array[i], &array[j], size, array);
			}
		}
	}
	if (array[last] != array[i + 1])
	{
		swap(&array[i + 1], &array[last], size, array);
	}
	return (i + 1);
}

/**
* quick_s - Function that sorts an array of integers in
* ascending order using the Quick sort algorithm.
*
* @array: this is the array to sort
* @start: NUmber to left
* @last: number to right
* @size: size of array
*/
void quick_s(int *array, int start, int last, size_t size)
{
	int piv = 0;

	if (last > start)
	{
		piv = separation(array, start, last, size);
		quick_s(array, start, piv - 1, size);
		quick_s(array, piv + 1, last, size);
	}
}


/**
 * quick_sort - Function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: Array
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = 0;

	end = size - 1;

	quick_s(array, start, end, size);
}
