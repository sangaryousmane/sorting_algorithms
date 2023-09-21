#include "sort.h"


/**
 * swapper - swaps two items of an array
 * @array: array to swap
 * @first: first item
 * @second: the second item
 * Return: nothin
 */
void swapper(int *array, int first, int second)
{
	int temp;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}


/**
* bubble_sort - swaps adjacent elements until it's fully sorted
* @array: the array to sort
* @size: size of the array
* Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int isSwapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		isSwapped = 0;

		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swapper(array, array[j], array[j - 1]);
				print_array(array, size);
				isSwapped = 1;
			}
		}
		if (isSwapped != 0)
			break;
	}
}
