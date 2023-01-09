#include "includes/push_swap.h"

//push back the number from B to A untill nothing left in B
void	pb_to_a(t_stack **a, t_stack **b)
{
	while (*b != NULL)
		pa(a, b);
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

//find the biggest number on the list
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

void	print_result(t_stack **number)
{
    t_stack *asd = *number;
   	while ( asd != NULL) {
        ft_printf("%d ", asd->number);
        asd = asd->next;
    }
	write(1, "\n", 1);
}
