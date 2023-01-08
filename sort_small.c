#include "includes/push_swap.h"

/*
check if the numbers are in the right order if so return
2 numbers -> switch them
3 numbers -> sort_3
3 < numbers < 6 -> sort_5
push back from B the 2 smallest to A
*/
void	sort_small(t_stack **a, t_stack **b, int length)
{
	if(in_order(*a) == 0)
		return ;
	if (length == 2)
	{
		sa(a);
		return ;
	}
	if (length > 3 && length < 6)
		sort_5(a, b, length);
	if (in_order(*a) == 1)
		sort_3(a);
	pb_to_a(a, b);
	
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

/*
move the smallest number to stack B until we have 3 numbers left in A
*/
void	sort_5(t_stack **a, t_stack **b, int length)
{
	int	position;
	int	min;
	int	mid;

	while (length > 3)
	{
		min = get_smallest_number(*a);
		mid = length / 2;
		position = get_min_position(*a, min);
		while (position != 1)
		{
			if (position <= mid)
				ra(a);
			else if (position > mid)
				rra(a);	
			// if (in_order(*a) == 0)
			// 	return ;
			position = get_min_position(*a, min);
		}
		pb(a, b);
		length--;
	}
}

/*
get the position of the min number on the list
*/
int	get_min_position(t_stack *number, int position)
{
	int pos;

	if(!number)
		return(1);
	pos = 1;
	while (number != NULL)
	{
		if (number->number == position)
			return(pos);
		number = number->next;
		pos++;
	}
	return(1);
}

//find the smallest number on the list
int	get_smallest_number(t_stack *number)
{
	int	min;

	min = number->number;
	while (number != NULL)
	{
		if (number->number < min)
			min = number->number;
		number = number->next;
	}
	return(min);
}

void	pb_to_a(t_stack **a, t_stack **b)
{
	while (*b != NULL)
		pa(a, b);
}