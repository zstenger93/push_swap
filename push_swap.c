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


//mini list
//small list
//medium list
//big list
//XXL list?
#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	list_length;
	int i;

	i = 0;
	a = NULL;
	b = NULL;
	if (create_stack_a(argc, argv, &a) == 1)
	{
		printf("Error!");
		free_stack(&a);
		return(0);
	}
	print(&a);
	printf("\n");
	list_length = list_size(a);
	speed_is_life(&a, &b, list_length);
	print(&a);
	free_stack(&a);
	free_stack(&b);
	return(0);
}

void	speed_is_life(t_stack **a, t_stack **b, int length)
{
	if (length > 2 && length <= 10)
		sort_small(a, b, length);
	// if (length > 10 && length <= 100)
	// 	sort_medium(a, b, length);
	// if (length > 100 && length <= 500)
	// 	sort_big(a, b, length);
	// if (length > 500)
	// 	sort_xxl(a, b, length);
}

void print(t_stack **a)
{
    t_stack *asd = *a;
   	while ( asd != NULL) {
        printf("%d\n", asd->number);
        asd = asd->next;
    }
}