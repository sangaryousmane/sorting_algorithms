#include "sort.h"



/**
 * swapper - swaps two elements of an array
 * @a: first element
 * @b: second element
 * Return: nothing
 */
void swapper(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swapper(&array[j], &array[j - 1]);
				print_array(array, size);
			}
		}
	}
}
