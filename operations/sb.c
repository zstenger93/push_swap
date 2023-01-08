#include "../includes/push_swap.h"

void	sb(t_stack **number)
{
	t_stack *temp;

	if(*number == NULL)
		return ;
	temp = *number;
	*number = (*number)->next;
	temp->next = (*number)->next;
	(*number)->next = temp;
	write(1, "sb\n", 3);
}
