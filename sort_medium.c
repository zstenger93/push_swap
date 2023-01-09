#include "includes/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b, int length)
{
	
	chunk_it_up(a, length);
	index_it_in_order(a, length);

}

int	get_biggest_number(t_stack *number)
{
	int	max;

	max = number->number;
	while (number != NULL)
	{
		if (number->number > max)
			max = number->number;
		number = number->next;
	}
	return(max);
}

t_chunk	chunk_it_up(t_stack *a, int length)
{
	int i;
	int chunk_size;
	t_chunk	chunk;

	chunk.start = a;
	chunk_size = chunk_norris(length);
	i = 0;
	while (i < chunk_size && a != NULL)
	{
		a = a->next;
		i++;
	}
	chunk.end = a;
	return(chunk);
}

int	chunk_norris(int length)
{
	int chunks;

	chunks = 0;
	if (length <= 25)
		chunks = 2;
	else if (length <= 50)
		chunks = 4;
	else if (length <= 100)
		chunks = 5;
	return(chunks);
}


// {
// 	int	i;
// 	int nbr;
// 	t_stack *list_index;
// 	t_stack *temp;

// 	list_index = NULL;
// 	temp = NULL;
// 	i = 0;
// 	while (i < length)
// 	{
// 		nbr = get_biggest_number(*a);
// 		temp = lstnew(nbr);
// 		add_back(&list_index, temp);
// 		i++;
// 	}
// 	print(&list_index);
// 	free_stack(&list_index);
// 	if (length == 100)
// 		ss(a, b);
	
// }