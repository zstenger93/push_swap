#include "../includes/push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*head;

	head = *b;
	while((*b)->next != NULL)
		*b = (*b)->next;
	(*b)->next = head;
	head = head->next;
	*b = (*b)->next;
	(*b)->next = NULL;
	*b = head;
}