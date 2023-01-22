/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:21 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/22 14:25:00 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_calculation
{
	int	min;
	int	max;
	int	next;
}t_calculation;

//check the input and create a list
int		list_size(int argc, char **argv);
int		list_is_in_order(int *list, int length);
void	check_for_doubles(int *list, int length);
void	create_list(int length, int *list_a, char **argv);

//pick a sorting method
void	speed_is_life(int *a, int *b, int length);

//small sort
void	sort_3(int *a);
void	sort_5(int *a, int length);
void	sort_smaller(int *a, int length);

//ra, rb, rr, rra, rrb, rrr, sa, sb, ss
void	sa_or_sb(int *list, int swap);
void	ra_or_rb(int *list, int length);
void	rra_or_rrb(int *list, int length);
void	ra_or_rra(int *list, int length, int max);
void	rb_or_rrb(int *list, int b_length, int max);

//min, max and next max
int		get_biggest_number(int *list, int length);
int		get_smallest_number(int *list, int length);
int		get_next_biggest_number(int *list, int length);

//big sort
void	sort_to_a(int *list, int b_length);
void	sort_bigger(int *a, int *b, int length);
int		is_pivot_here(int *list, int length, int mid);
int		pivot_finder(int *list, int b_length, int length);
int		pick_divider(int length, int a_length, int smaller);
int		calculate_position(int *list, int mid, int b_length, int length);

//checker
char	*read_terminal(char *operation_list);
char	*next_operation(char *operation_list);
void	result(char *operation_list, int length);
void	is_valid_operation(char *operation, char *operation_list);
void	execute_operations(char *operation_list, int *a, int *b, int b_len);
void	grademe(int *list, char *operation_list, int length);
void	two_or_three(int operation_count, int length);
void	points(int operation_count, int length);
void	fivehundred(int operation_count);
void	hundred(int operation_count);
void	five(int operation_count);

#endif