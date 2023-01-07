#include "../includes/push_swap.h"

int list_size(t_stack *a)
{
	int length;
	if(!a)
		return(0);
	while (a != NULL)
	{
		a = a->next;
		length++;
	}
	return(length);
}
