#include "sort.h"

/**
 * swp_ints - swap two ints in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swp_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * shell_sort - sort an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: array of ints.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t g, a, b;

	if (array == NULL || size < 2)
		return;

	for (g = 1; g < (size / 3);)
		g = g * 3 + 1;

	for (; g >= 1; g /= 3)
	{
		for (a = g; a < size; a++)
		{
			b = a;
			while (b >= g && array[b - g] > array[b])
			{
				swp_ints(array + b, array + (b - g));
				b -= g;
			}
		}
		print_array(array, size);
	}
}
