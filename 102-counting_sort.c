#include "sort.h"
int _max_number(int *array, size_t size);
/**
 * counting_sort - function that sorts an array of
 * integers in ascending order using the Counting
 * sort algorithm
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max, i, num;
	size_t j;

	if (array == NULL || size <= 1)
		return;
	max = _max_number(array, size);
	count = malloc(sizeof(size_t) * (max + 1));
	output = malloc(sizeof(size_t) * size);
	for (i = 0; i < max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
	{
		num = array[j];
		count[num] += 1;
	}
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	/*
	* Find the index of each element of the original array in count array,
	* and place the elements in output array
	*/

	for (j = 0; j < size; j++)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}

	/*
	* Copy the sorted elements into original array
	*/

	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}
/**
 * _max_number - Find the max number
 * @array:  array of integer
 * @size: array's size
 * Return: integer
 */
int _max_number(int *array, size_t size)
{
	size_t i;
	int max_number = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_number)
		max_number = array[i];
	}
	return (max_number);
}
