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
bool	list_is_in_order(t_stack *number)
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
void	add_to_end_of_list(t_stack **list, t_stack *new_node)
{
	t_stack	*temp;

	if (!new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

//create a new node for the list
t_stack	*create_new_node(int value)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->number = value;
	result->next = NULL;
	return (result);
}
