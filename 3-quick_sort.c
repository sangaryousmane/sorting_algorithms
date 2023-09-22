#include "sort.h"



/**
 * swap - swaps two elements of an array
 * @start: first element
 * @end: second element
 * @size: the array's size
 * @nums: the array
 * Return: nothing
 */
void swap(int *nums, size_t size, int start, int end)
{
	int temp;

	if (nums[start] != nums[end])
	{
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		print_array(nums, size);
	}
}


/**
 * partition - implements the lomuto partition
 * @nums: the array to partition
 * @start: the start element
 * @end: the last element
 * @size: the array's size
 * Return: index of the pivot element
 */
int partition(int *nums, size_t size, int start, int end)
{
	int pivot = nums[end];
	int i = start - 1, j;

	for (j = start; j <= end; j++)
	{
		if (nums[j] < pivot)
		{
			i++;
			swap(nums, size, i, j);
		}
	}
	swap(nums, size, i + 1, end);
	return (i + 1);
}



/**
 * quick_sort_helper - helps in the implementation of quick sort
 * @nums: the array to sort
 * @size: the size of the array
 * @start: the array start
 * @end: last index
 * Return: nothing
 */
void quick_sort_helper(int *nums, size_t size, int start, int end)
{
	int piv_index;

	if (start < end)
	{
		piv_index = partition(nums, size, start, end);
		quick_sort_helper(nums, size, start, piv_index - 1);
		quick_sort_helper(nums, size, piv_index + 1, end);
	}
}


/**
 * quick_sort - implements quick sort using lomuto partition
 * @nums: the array to sort
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort(int *nums, size_t size)
{
	if (nums == NULL || size < 2)
		return;
	quick_sort_helper(nums, size, 0, size - 1);
}
