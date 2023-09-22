#include "sort.h"


/**
 * partition - implements the lomuto partition
 * @arr: the array to partition
 * @low: the lowest element
 * @high: the highest element
 * Return: index of the pivot element
 */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, i);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}



/**
 * quick_sort - implements quick sort using the Lomuto algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	int pivot_index = partition(array, 0, size - 1);

	print_array(array, size);
	partition(array, pivot_index);
	partition(array, pivot_index + 1, size - pivot_index - 1);
}
