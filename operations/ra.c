#include "../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while((*a)->next != NULL)
		*a = (*a)->next;
	(*a)->next = head;
	head = head->next;
	*a = (*a)->next;
	(*a)->next = NULL;
	*a = head;
	write(1, "ra\n", 3);
}