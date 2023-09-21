#include "sort.h"

/**
* bubble_sort - swaps adjacent elements until it's fully sorted
* @array: the array to sort
* @size: size of the array
* Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				int temp;
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
			}
		}
	}
}
