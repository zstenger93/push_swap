#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX "2147483647"
# define INT_MIN "-2147483647"



# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long	number;
	struct s_stack	*next;
	// t_stack *a;
	// t_stack *b;
}t_stack;

//swap the first 2 elements on the top of a or b
void	sa(t_stack **number);
void	sb(t_stack **number);
void	ss(t_stack **a, t_stack **b);

//take first element at the top of b and put it on the top of a
//take first element at the top of a and put it on the top of b
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//shift up all element of stack a or b by 1
void	ra(t_stack **number);
void	rb(t_stack **number);

//shift down all elements of stack a or b by 1 or both
void	rra(t_stack **number);
void	rrb(t_stack **number);
void	rrr(t_stack **a, t_stack **b);


#endif