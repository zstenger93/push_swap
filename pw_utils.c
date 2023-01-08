#include "includes/push_swap.h"

//get the length of the list
int list_size(t_stack *a)
{
	int length;
	if(!a)
		return(0);
	length = 0;
	while (a != NULL)
	{
		a = a->next;
		length++;
	}
	return(length);
}

//check if the list is in the correct order
bool	in_order(t_stack *number)
{
	if (!number->next)
		return(1);
	while(number->next != NULL)
	{
		if (number->number > number->next->number)
			return(1);
		number = number->next;
	}
	return(0);
}

//free the stacks? mAyBeEe
void	free_stack(t_stack **number)
{
	t_stack *temp;

	if ((!number) || (!*number))
		return ;
	while (*number != NULL)
	{
		temp = (*number)->next;
		free(*number);
		(*number) = temp;
	}
	*number = NULL;
}

//add a node at the end of the list
void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

//create a new node for the list
t_stack	*lstnew(int value)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->number = value;
	result->next = NULL;
	return (result);
}

// get the mid element of the list, set it 1 step closer to the start
// int	get_mid_element(int size)
// {
// 	int	mid;

// 	if (size % 2 == 0)
// 		mid = (size / 2) + 1;
// 	else
// 		mid = (size / 2);
// 	return(mid);
// }