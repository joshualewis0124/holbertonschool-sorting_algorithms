#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 *
 * @list: The list to be printed
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL;
	bool trig = false;

	if (!list || !(*list) || !(*list)->next)
		return;

	aux = *list;
	while (aux->next)
	{
		if (aux->n > (aux->next)->n)
		{
			(aux->next)->prev = aux->prev;

			if ((aux->next)->prev)
				(aux->prev)->next = aux->next;
			else
				*list = aux->next;

			aux->prev = aux->next;
			aux->next = (aux->next)->next;
			(aux->prev)->next = aux;
			if (aux->next)
				aux->next->prev = aux;
			aux = aux->prev;
			print_list(*list);

			if (aux->prev && aux->prev->n > aux->n)
			{
				aux = aux->prev;
				trig = true;
			}
		}
		if (trig == false)
			aux = aux->next;
		else
			trig = false;
	}
}
