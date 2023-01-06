#include "../includes/push_swap.h"

void	sb(t_stack **number)
{
	t_stack *temp;

	if(*number == NULL)
		return(0);
	temp = *number;
	*number = (*number)->next;
	temp->next = (*number)->next;
	(*number)->next = temp;
}