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
 * bubble_sort - Sort an array of ints in ascending order
 * @array: array of integers to sort.
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t c, l = size;
	bool b = false;

	if (array == NULL || size < 2)
		return;

	while (b == false)
	{
		b = true;
		for (c = 0; c < l - 1; c++)
		{
			if (array[c] > array[c + 1])
			{
				swp_ints(array + c, array + c + 1);
				print_array(array, size);
				b = false;
			}
		}
		l--;
	}
}
