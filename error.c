#include "includes/push_swap.h"

void	error(t_stack **a, t_stack **b)
{
	ft_printf("\e[1;4;31mError!\e[0m\n");
	free_stack(a);
	free_stack(b);
	exit(1);
}
