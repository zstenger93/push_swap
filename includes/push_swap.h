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
	long	number;
	int index;
	int chunky;
	struct s_stack	*next;
}t_stack;

//if there is and the provided list is correct then create stack A
bool	create_stack_a(int argc, char **argv, t_stack **a);
void	raw_input(int argc, char **argv, t_stack **a);
void	add_to_end_of_list(t_stack **list, t_stack *new_node);
t_stack	*create_new_node(int value);

//pick a sorting method based on the size of the provided list
void	speed_is_life(t_stack **a, t_stack **b, int length);

//SMALLER LISTS
void	sort_smaller(t_stack **a, t_stack **b, int length);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b, int legnth);

//BIGGER LISTS
void	sort_bigger(t_stack **a, t_stack **b, int length);

//OPERATIONS
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

//CHUNK OPERATIONS
//choose the amount of chuck's, I mean chunks and create the chunks
int		chunk_norris(int length);
void	chunk_it_up(t_stack *a, int length, int chunks);

//chunk utils
void	pb_to_a(t_stack **a, t_stack **b);

//basic utils
int		list_size(t_stack *a);
void	free_stack(t_stack **number);
int		get_biggest_number(t_stack *number);
int		get_smallest_number(t_stack *number);
int		get_min_position(t_stack *number, int min);
bool	list_is_in_order(t_stack *number);
void	print_result(t_stack **number);
void	error(t_stack **a, t_stack **b);

//stack utils
int get_index_of_number(t_stack *a, int nbr);
int		get_mid(int size);

void	sort_to_b(t_stack **a, t_stack **b, int length);
void	sort_to_a(t_stack **a, t_stack **b, int length);
void	get_indexed_list_a(t_stack *a, int length);
t_stack	*set_the_index(t_stack *list);

#endif