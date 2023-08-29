#include "sort.h"

void swp_ints(int *a, int *b);
void bitonic_mer(int *array, size_t size, size_t st, size_t se, char flow);
void bitonic_seq(int *array, size_t size, size_t st, size_t se, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swp_ints - sway 2 integers in an array.
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
 * bitonic_mer - sort a bitonic sequence inside an array of integers.
 * @array: array of ints.
 * @size: size of the array.
 * @st: starting index of the sequence in array.
 * @se: size of the sequence.
 * @flow: direction to sort in.
 */
void bitonic_mer(int *array, size_t size, size_t st, size_t se, char flow)
{
	size_t a, j = se / 2;

	if (se > 1)
	{
		for (a = st; a < st + j; a++)
		{
			if ((flow == UP && array[a] > array[a + j]) ||
			(flow == DOWN && array[a] < array[a + j]))
			swp_ints(array + a, array + a + j);
		}
		bitonic_mer(array, size, st, j, flow);
		bitonic_mer(array, size, st + j, j, flow);
	}
}

/**
 * bitonic_seq - convert an array of ints into a bitonic sequence.
 * @array: array of ints
 * @size: size of the array
 * @st: starting index of a block of the building bitonic sequence.
 * @se: size of a block of the building bitonic sequence.
 * @flow: direction to sort the bitonic sequence blck in.
 */
void bitonic_seq(int *array, size_t size, size_t st, size_t se, char flow)
{
	size_t c = se / 2;
	char *s = (flow == UP) ? "UP" : "DOWN";

	if (se > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", se, size, s);
		print_array(array + st, se);

		bitonic_seq(array, size, st, c, UP);
		bitonic_seq(array, size, st + c, c, DOWN);
		bitonic_mer(array, size, st, se, flow);

		printf("Result [%lu/%lu] (%s):\n", se, size, s);
		print_array(array + st, se);
	}
}

/**
 * bitonic_sort - sort an array of integers in ascending order
 * using the bitonic sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
