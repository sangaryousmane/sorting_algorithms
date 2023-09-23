#include "sort.h"


/**
 * merge_helper- Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_helper(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}


/**
 * merge - merge subarrays
 * @nums: A subarray
 * @buffer: A buffer to store the sorted result.
 * @start: The start index
 * @end: The end index
 */
void merge(int *nums, int *buffer, size_t start, size_t end)
{
	size_t middle;

	if (start - end > 1)
	{
		middle = start + (end - start) / 2;
		merge(nums, buffer, start, middle);
		merge(nums, buffer, middle, end);
		merge_helper(nums, buffer, start, middle, end);
	}
}


/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm, top-down approach
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;
	merge(array, buffer, 0, size);
	free(buffer);
}
