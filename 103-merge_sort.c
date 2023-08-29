#include "sort.h"

void merge_sarray(int *sarray, int *bff, size_t f, size_t m, size_t b);
void merge_sort_rec(int *sarray, int *bff, size_t f, size_t b);
void merge_sort(int *array, size_t size);

/**
 * merge_sarray - sort a subarray of ints.
 * @sarray: subarray of an array of ints to sort.
 * @bff: buffer to store the sorted subarray.
 * @f: front index of the array.
 * @m: middle index of the array.
 * @b: back index of the array.
 */
void merge_sarray(int *sarray, int *bff, size_t f, size_t m, size_t b)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(sarray + f, m - f);

	printf("[right]: ");
	print_array(sarray + m, b - m);

	for (x = f, y = m; x < m && y < b; z++)
		bff[z] = (sarray[x] < sarray[y]) ? sarray[x++] : sarray[y++];
	for (; x < m; x++)
		bff[z++] = sarray[x];
	for (; y < b; y++)
		bff[z++] = sarray[y];
	for (x = f, z = 0; x < b; x++)
		sarray[x] = bff[z++];

	printf("[Done]: ");
	print_array(sarray + f, b - f);
}

/**
 * merge_sort_rec - implement the merge sort algorithm through recursion.
 * @sarray: subaray of an array of ints to sort.
 * @bff: buffer to store the sorted result.
 * @f: front index of the subarray.
 * @b: back index of the subarray.
 */
void merge_sort_rec(int *sarray, int *bff, size_t f, size_t b)
{
	size_t m;

	if (b - f > 1)
	{
		m = f + (b - f) / 2;
		merge_sort_rec(sarray, bff, f, m);
		merge_sort_rec(sarray, bff, m, b);
		merge_sarray(sarray, bff, f, m, b);
	}
}

/**
 * merge_sort - sort an array of ints in ascending order
 * using the merge sort algorithm.
 * @array: aray of ints.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *bff;

	if (array == NULL || size < 2)
		return;

	bff = malloc(sizeof(int) * size);
	if (bff == NULL)
		return;

	merge_sort_rec(array, bff, 0, size);

	free(bff);
}
