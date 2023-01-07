#include "includes/push_swap.h"

void	sort_small(t_stack **a, t_stack **b, int length)
{
	if (length == 2)
	{
		if (a[0] > a[1])
			sa(a);
		return ;
	}
	if (length == 3)
		sort_3(a);
	else
		sort_up_to_10(a, b, length);
}

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
	if((first > second) && (first < third) && (second < third))
		sa(a);
	else if((first > second) && (first > third) && (second > third))
	{
		sa(a);
		rra(a);
	}
	else if((first > second) && (first > third) && (second < third))
		ra(a);
	else if((first < second) && (first < third) && (second > third))
	{
		sa(a);
		ra(a);
	}
	else if((first < second) && (first > third) && (second > third))
		rra(a);
}

void	sort_up_to_10(t_stack **a, t_stack **b, int length)
{
	int	position;
	int	min;
	int	mid;

	while (length > 3)
	{
		min = get_smallest_number(a);
		mid = length / 2;
		position = get_min_position(a, min);
		while (position != 0)
		{
			if (position <= mid)
				ra(a);
			else if (position > mid)
				rra(a);
			if (in_order(a) == true)
				return ;
			position = get_min_position(a, min);
		}
		pb(a, b);
		length--;
	}
}

int	get_min_position(t_stack **number, int position)
{
	int i;

	if(!*number)
		return(0);
	i = 0;
	while (*number != NULL && i != position)
	{
		*number = (*number)->next;
		i++;
	}
	return(1);
}

int	get_smallest_number(t_stack **number)
{
	int	min;

	min = (*number)->number;
	while ((*number) != NULL)
	{
		if ((*number)->number < min)
			min = (*number)->number;
		(*number) = (*number)->next;
	}
	return(min);
}