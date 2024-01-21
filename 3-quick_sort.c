#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @lower: The low index of the partition
 * @higher: The high index of the partition
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
int l_p = 0;

if (lower < higher)
{
l_p = lomuto_partition(array, lower, higher, size);
quick_sort_rec(array, lower, l_p - 1, size);
quick_sort_rec(array, l_p + 1, higher, size);
}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @lower: The low index of the partition
 * @higher: The high index of the partition
 * @size: The size of the array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
int i = 0, j = 0, pivot = 0, aux = 0;

pivot = array[higher];
i = lower;

for (j = lower; j < higher; ++j)
{
if (array[j] < pivot)
{
aux = array[i];
array[i] = array[j];
array[j] = aux;

if (aux != array[i])
print_array(array, size);

++i;
}
}

aux = array[i];
array[i] = array[higher];
array[higher] = aux;

if (aux != array[i])
print_array(array, size);

return (i);
}
