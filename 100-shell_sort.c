#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 * Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t j, i, interval;

	/* Calculate the initial interval using Knuth sequence */
	for (interval = 1; interval <= size / 3; interval = interval * 3 + 1)
	{
	}
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Sort the sub-array using insertion sort */
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}


		for (i = 0; i < size; i++)
		{
			printf("%d", array[i]);
			if (i != size - 1)
				printf(", ");
		}
		printf("\n");

		/* Calculate the next interval using Knuth sequence */
		interval = (interval - 1) / 3;
	}
}
