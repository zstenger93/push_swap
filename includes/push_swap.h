/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:21 by zstenger          #+#    #+#             */
/*   Updated: 2023/02/10 16:47:41 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_calculation
{
	int	min;
	int	max;
	int	next;
}t_calculation;

//check the input and create a stack
int		stack_size(int argc, char **argv);
void	is_argv_valid(int argc, char **argv);
int		stack_is_in_order(int *stack, int len);
void	check_for_doubles(int *stack, int len);
void	create_stack(int len, int *stack_a, char **argv);

//pick a sorting method
void	speed_is_life(int *a, int *b, int len);

//small sort
void	sort_3(int *a);
void	sort_5(int *a, int len);
void	sort_smaller(int *a, int len);

//ra, rb, rr, rra, rrb, rrr, sa, sb, ss
void	sa_or_sb(int *stack, int swap);
void	ra_or_rb(int *stack, int len);
void	rra_or_rrb(int *stack, int len);
void	ra_or_rra(int *stack, int len, int max);
void	rb_or_rrb(int *stack, int b_len, int max);

//min, max and next max
int		get_biggest_number(int *stack, int len);
int		get_smallest_number(int *stack, int len);
int		get_next_biggest_number(int *stack, int len);

//big sort
void	sort_to_a(int *stack, int b_len);
void	sort_bigger(int *a, int *b, int len);
int		pivot_finder(int *stack, int b_len, int len);
int		pick_divider(int len, int a_len, int smaller);
int		is_pivot_here(int *stack, int len, int pivot);
int		sort_b_to_a(int *stack, int b_len, int i, int j);
int		calculate_position(int *stack, int pivot, int b_len, int len);

//checker
char	*read_stdin(char *operation_list);
char	*next_operation(char *operation_list);
void	result(char *operation_list, int len);
void	is_valid_operation(char *operation, char *operation_list);
void	execute_operations(char *operation_list, int *a, int *b, int b_len);
void	grademe(int *stack, char *operation_list, int len);
void	two_or_three(int operation_count, int len);
void	output3(int operation_count, int len);
void	output2(int operation_count, int len);
void	output(int operation_count, int len);
void	points(int operation_count, int len);
void	fivehundred(int operation_count);
void	hundred(int operation_count);
void	five(int operation_count);
void	sign(void);

#endif