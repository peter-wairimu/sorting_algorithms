#include "sort.h"

/**
 * swap - swap two elements in an integer array
 * @array: the int array containing the elements
 * @a: index of the first element
 * @b: index of the second element
 *
 * Return: void
 */

void swap(int *array, int a, int b)
{
	if (a == b)
		return;
	array[a] ^= array[b];
	array[b] ^= array[a];
	array[a] ^= array[b];
}

/**
 * partition - partitions array into subarrays and sorts if possible
 * @array: the int array to partition and sort
 * @low: the lower bound
 * @high: the upper bound
 * @size: size of the array
 *
 * Return: the index of the border of the new partition
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int a, b;

	b = low;
	for (a = low; a < high; a++)
	{
		if (array[a] < pivot)
		{
			if (b != a)
			{
				swap(array, a, b);
				print_array(array, size);
			}
			b++;
		}
	}
	if (b != high)
	{
		swap(array, b, high);
		print_array(array, size);
	}
	return (b);
}

/**
 * quick - quick sort uses a recursive function to sort the array
 * @array: the int array to sort
 * @low: the lower bound
 * @high: the upper bound
 * @size: size of the array
 *
 * Return: void
 */

void quick(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high, size);
		quick(array, low, part - 1, size);
		quick(array, part + 1, high, size);
	}
}

/**
 * quick_sort - sort an integer array using quick sort
 * @array: the array to sort
 * @size: the size of the array
 *
 * Description: Sort an array of integers in ascending order using the quick
 * sort with the Lomuto partition scheme. Use the last element of the partition
 * as the pivot. Print the array every time two elements are swapped.
 */

void quick_sort(int *array, size_t size)
{
	/* declarations */

	if (size <= 1)
		return;

	quick(array, 0, size - 1, size);
}
