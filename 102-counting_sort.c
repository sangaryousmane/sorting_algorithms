#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	int *count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (size_t i = 0; i < size; i++)
		count[array[i]]++;

	printf("Counting array:");
	for (int i = 0; i <= max; i++)
		printf(" %d", count[i]);
	printf("\n");

	int *output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		output[i] = 0;
	}

	for (size_t i = 0, j = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			output[j] = i;
			j++;
			count[i]--;
		}
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

