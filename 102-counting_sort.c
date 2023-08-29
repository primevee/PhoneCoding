#include "sort.h"

/**
 * get_mv - get max value in an array of ints.
 * @array: the array of ints.
 * @size: size of the array.
 *
 * Return: the maximum integer in the array.
 */
int get_mv(int *array, int size)
{
	int m, a;

	for (m = array[0], a = 1; a < size; a++)
	{
		if (array[a] > m)
			m = array[a];
	}

	return (m);
}

/**
 * counting_sort - sort an array of ints in ascending
 * order using the counting sort algorithm.
 * @array: array of ints.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *c, *std, m, a;

	if (array == NULL || size < 2)
		return;

	std = malloc(sizeof(int) * size);
	if (std ==  NULL)
		return;
	m = get_mv(array, size);
	c = malloc(sizeof(int) * (m + 1));
	if (c == NULL)
	{
		free(std);
		return;
	}

	for (a = 0; a < (m + 1); a++)
		c[a] = 0;
	for (a = 0; a < (int)size; a++)
		c[array[a]] += 1;
	for (a = 0; a < (m + 1); a++)
		c[a] += c[a - 1];
	print_array(c, m + 1);

	for (a = 0; a < (int)size; a++)
	{
		std[c[array[a]] - 1] = array[a];
		c[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = std[a];

	free(std);
	free(c);
}
