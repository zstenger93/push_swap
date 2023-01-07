#include "../includes/push_swap.h"

void	rrb(t_stack **b)
{
	t_stack	*head;
	t_stack	*start;
	t_stack	*end;

	head = *b;
	start = *b;
	end = *b;
	while (start->next != NULL)
	{
		start = start->next;
		if (start->next != NULL)
			end = end->next;
	}
	if (start->next == NULL)
	{
		start->next = head;
		end->next= NULL;
	}
	*b = start;
}