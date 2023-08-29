#include "sort.h"

void swp_ints(int *a, int *b);
int hoare_part(int *array, size_t size, int l, int r);
void hoare_sort(int *array, size_t size, int l, int r);
void quick_sort_hoare(int *array, size_t size);

/**
 * swp_ints - swap 2 integers in an array.
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
 * hoare_part - order a subset of an array of ints
 * according to the hoare partition scheme.
 * @array: array of ints
 * @size: size of the array
 * @l: starting index of the subset
 * @r: ending index of the subset
 *
 * Return: final partition index
 */
int hoare_part(int *array, size_t size, int l, int r)
{
	int pvt, abv, bel;

	pvt = array[r];
	for (abv = l - 1, bel = r + 1; abv < bel;)
	{
		do {
			abv++;
		} while (array[abv] < pvt);
		do {
			bel--;
		} while (array[bel] > pvt);

		if (abv < bel)
		{
			swp_ints(array + abv, array + bel);
			print_array(array, size);
		}
	}

	return (abv);
}

/**
 * hoare_sort - implement the quicksort algorithm through recursion.
 * @array: array of ints to sort.
 * @size: size of the array.
 * @l: starting index of the array partition.
 * @r: ending index of the array partition.
 */
void hoare_sort(int *array, size_t size, int l, int r)
{
	int prt;

	if (r - l > 0)
	{
		prt = hoare_part(array, size, l, r);
		hoare_sort(array, size, l, prt - 1);
		hoare_sort(array, size, prt, r);
	}
}

/**
 * quick_sort_hoare - sort an array of integers in ascending order
 * using the quicksort algorithm.
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
