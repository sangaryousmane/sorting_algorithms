#ifndef _SORT_H
#define _SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/** Helper functions **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *nums, size_t size, int start, int end);
int partition(int *nums, size_t size, int start, int end);
void quick_sort_helper(int *nums, size_t size, int start, int end);
void merge_subarr(int *subarr, int *buff, size_t front,
size_t mid, size_t back);
void merge(int *nums, int *buffer, size_t start, size_t end);


/** SORTING FUNCTIONS **/
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
#endif /** _SORT_H **/
