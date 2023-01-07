#include "../includes/push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp_a;

	if(*a == NULL)
		return ;
	temp_a = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp_a;
}
