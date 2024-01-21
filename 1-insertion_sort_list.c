#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

listint_t *current = (*list)->next;
listint_t *temp;

while (current != NULL)
{
temp = current;

while (temp->prev != NULL && temp->n < temp->prev->n)
{
temp->prev->next = temp->next;

if (temp->next != NULL)
temp->next->prev = temp->prev;

temp->next = temp->prev;
temp->prev = temp->prev->prev;

if (temp->prev != NULL)
temp->prev->next = temp;

if (temp->prev == NULL)
*list = temp;

print_list(*list);
}

current = current->next;
}
}
