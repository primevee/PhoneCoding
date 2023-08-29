#include "sort.h"

int get_mv(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *bff);
void radix_sort(int *array, size_t size);

/**
 * get_mv - get the maximum value in an array of ints.
 * @array: array of ints.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
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
 * radix_count_sort - sort the significant digits of an array of ints
 * in ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort on.
 * @buff: buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		c[(array[a] / sig) % 10] += 1;

	for (a = 0; a < 10; a++)
		c[a] += c[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		buff[c[(array[a] / sig) % 10] - 1] = array[a];
		c[(array[a] / sig) % 10] -= 1;
	}

	for (a = 0; a < size; a++)
		array[a] = buff[a];
}

/**
 * radix_sort - sort an array of integers in ascending order
 * using the radix sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int m, s, *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	m = get_mv(array, size);
	for (s = 1; m / s > 0; s *= 10)
	{
		radix_count_sort(array, size, s, b);
		print_array(array, size);
	}

	free(b);
}
