#include "sort.h"

void swp_ints(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swp_ints - swap two integers in an array.
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
 * heapify - turn a binary tree into a complete binary heap.
 * @array: array of ints representing a binary tree.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, lg;

	l = 2 * root + 1;
	r = 2 * root + 2;
	lg = root;

	if (l < base && array[l] > array[lg])
		lg = l;
	if (r < base && array[r] > array[lg])
		lg = r;

	if (lg != root)
	{
		swp_ints(array + root, array + lg);
		print_array(array, size);
		heapify(array, size, base, lg);
	}
}

/**
 * heap_sort - sort an array of ints in ascending order
 * using the heap sort algorithm.
 * @array: an array of ints.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		heapify(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swp_ints(array, array + a);
		print_array(array, size);
		heapify(array, size, a, 0);
	}
}
