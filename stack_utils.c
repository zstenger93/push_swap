#include "includes/push_swap.h"

// get the mid element of the list, set it 1 step closer to the start
int	get_mid(int size)
{
	int	mid;

	mid = (size / 2);
	return(mid);
}

int get_index_of_number(t_stack *a, int nbr)
{
	int i;

	i = 1;
	while (a->next != NULL)
	{
		if (a->number == nbr)
			return(i);
		i++;
		a = a->next;
	}
	return(i);
}