#include "sort.h"

/**
 * swp_ints - Swap two ints in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swp_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *f;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		f = array + a;
		for (b = a + 1; b < size; b++)
			f = (array[b] < *f) ? (array + b) : f;

		if ((array + a) != f)
		{
			swp_ints(array + a, f);
			print_array(array, size);
		}
	}
}
