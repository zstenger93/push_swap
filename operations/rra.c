#include "../includes/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*head;
	t_stack	*start;
	t_stack	*end;

	head = *a;
	start = *a;
	end = *a;
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
	*a = start;
	write(1, "rra\n", 4);
}