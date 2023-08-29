#include "sort.h"

void swp_ints(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_part - order a subset of array of ints according to
 * the lomuto partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset.
 * @right: ending index of the subset.
 *
 * Return: final partition index.
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pvt, abv, bel;

	pvt = array + right;
	for (abv = bel = left; bel < right; bel++)
	{
		if (array[bel] < *pvt)
		{
			if (abv < bel)
			{
				swp_ints(array + bel, array + abv);
				print_array(array, size);
			}
			abv++;
		}
	}

	if (array[abv] > *pvt)
	{
		swp_ints(array + abv, pvt);
		print_array(array, size);
	}

	return (abv);
}

/**
 * lomuto_sort - implement quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition.
 * @right: ending index of the array partition.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, prt - 1);
		lomuto_sort(array, size, prt + 1, right);
	}
}

/**
 * quick_sort - sort an array of integers in s ascending order
 * using the quicksort algorithm.
 * @array: an array of integers.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
