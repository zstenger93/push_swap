// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.


//small list up to 5
	//mini list 2 & 3
//medium list up to 100
//big list up to 500
//XXL list? over 500
#include "includes/push_swap.h"

/*
create stack A from the input
choose the sorting method based on the length of the list
sort the list with the choosen method
free both stacks
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	list_length;

	a = NULL;
	b = NULL;
	if (create_stack_a(argc, argv, &a) == 1)
		error(&a, &b);
	list_length = list_size(a);
	speed_is_life(&a, &b, list_length);
	print_result(&a);
	free_stack(&a);
	free_stack(&b);
	// system("leaks push_swap");
	return(0);
}

/*
to choose the sorting method, because speed is life
2, 3 or 5
5 - 100
100 - 500
500 <
*/
void	speed_is_life(t_stack **a, t_stack **b, int length)
{
	if (length > 1 && length < 6)
		sort_smaller(a, b, length);
	if (length > 5)
		sort_bigger(a, b, length);
}
