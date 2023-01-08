#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack *temp_b;

	if(*b == NULL)
		return ;
	temp_b = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp_b;
	write(1, "pa\n", 3);
}