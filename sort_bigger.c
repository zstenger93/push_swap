#include "includes/push_swap.h"

void	sort_bigger(t_stack **a, t_stack **b, int length)
{
	// int i;
	int chunks;
	// int	chunk_number;

	if (list_is_in_order(*a) == 0)
		return ;
	get_indexed_list_a(*a, length);
	chunks = chunk_norris(length);
	chunk_it_up(*a, length, chunks);
	// chunk_number = (length / 100) + 3;
	// i = 0;
	// while ((chunk_number * i) < length)
	// {
	// 	move_chunks_to_b(a, b, length, chunks);
	// 	i++;
	// }
	sort_to_b(a, b, length);
	sort_to_a(a, b, length);
}

//index the list
void	get_indexed_list_a(t_stack *a, int length)
{
	int i;
	t_stack	*temp_list;
	t_stack	*temp;

	i = 1;
	temp = NULL;
	temp_list = a;
	while((length + 1) > i)
	{
		temp = set_the_index(temp_list);
		temp->index = i;
		i++;
	}
}

//return the numbers from bigger to smaller
t_stack	*set_the_index(t_stack *list)
{
	t_stack *temp;
	t_stack	*rtrn;

	rtrn = NULL;
	temp = list;
	while (temp)
	{
		while (rtrn == NULL)
		{
			if (temp->index == 0)
				rtrn = temp;
			temp = temp->next;
		}
		if (temp->number < rtrn->number && temp->index == 0)
			rtrn = temp;
		temp = temp->next;
	}
	return (rtrn);
}

void	sort_to_b(t_stack **a, t_stack **b, int length)
{
	int	mid;
	int index;

	while (length > 1)
	{
		if (get_smallest_number(*a) == (*a)->number)
			pb(a, b);
		mid = get_mid(length);
		index = get_index_of_number((*a), (*a)->number);
		if (mid > index && get_smallest_number(*a) != (*a)->number)
			ra(a);
		else if (get_smallest_number(*a) != (*a)->number)
			rra(a);
	}
	pb(a, b);
}

void	sort_to_a(t_stack **a, t_stack **b, int length)
{
	int mid;

	while((*b)->number == get_biggest_number(*b))
		pa(a, b);
	while (length > 0)
	{
		while (get_index_of_number(*b, get_biggest_number(*b)) != 1)
		{
			mid = get_mid(length);
			if (mid > get_index_of_number(*b, get_biggest_number(*b)))
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}