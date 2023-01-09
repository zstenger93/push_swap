#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX "2147483647"
# define INT_MIN "-2147483647"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	number;
	struct s_stack	*next;
}t_stack;

typedef struct s_chunk
{
	struct s_stack	*start;
	struct s_stack	*end;
}t_chunk;

//if there is and the provided list is correct then create stack A
bool	create_stack_a(int argc, char **argv, t_stack **a);
void	raw_input(int argc, char **argv, t_stack **a);
void	add_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int value);

//pick a sorting method based on the size of the provided list
void	speed_is_life(t_stack **a, t_stack **b, int length);

//small list
void	sort_small(t_stack **a, t_stack **b, int length);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b, int legnth);

//medium list
void	sort_medium(t_stack **a, t_stack **b, int length);
//choose the amount of chuck's, I mean chunks
int		chunk_norris(int length);

//big list
void	sort_big(t_stack **a, t_stack **b, int length);
//bigger list
void	sort_xxl(t_stack **a, t_stack **b, int length);

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

//utils for sorting
void	pb_to_a(t_stack **a, t_stack **b);

//utils
int		list_size(t_stack *a);
void	free_stack(t_stack **number);
int		get_biggest_number(t_stack *number);
int		get_smallest_number(t_stack *number);
int		get_min_position(t_stack *number, int min);
int		get_mid_element(int size);
bool	in_order(t_stack *number);
void	print(t_stack **number);


#endif