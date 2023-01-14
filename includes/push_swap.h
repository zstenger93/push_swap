/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:21 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/14 17:55:55 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_calculation
{
	int	min;
	int	max;
	int	next;
}t_calculation;

void	error(void);

//check the input and create a list
int		list_size(int argc, char **argv);
void	create_list(int length, int *list_a, char **argv);
void	check_for_doubles(int *list, int length);
int		list_is_in_order(int *list, int length);

//pick a sorting method
void	speed_is_life(int *a, int *b, int length);

//small sort
void	sort_smaller(int *a, int length);
void	sort_3(int *a);
void	sort_5(int *a, int length);

//ra, rb, rr, rra, rrb, rrr, sa, sb, ss
void	rotate_5(int *list, int length, int max);
void	rotate(int *list, int length);
void	reverse_rotate(int *list, int length);
void	rotate_b(int *list, int b_length, int max);
void	sa_or_sb(int *list, int argc);

//finding nemo, I mean numbers
int		get_smallest_number(int *list, int length);
int		get_biggest_number(int *list, int length);
int		get_next_biggest_number(int *list, int length);

//big sort
void	sort_bigger(int *a, int *b, int length);
int		pivot_finder(int *list, int b_length, int length);
int		calculation(int *list, int mid, int b_length, int length);
int		is_pivot_here(int *list, int length, int mid);
void	sort_to_a(int *list, int b_length);

//checker
char	*read_terminal(int argc, char **argv, char *operation_list);
void	is_valid_operation(char *operation, char *operation_list);
void	execute_operations(char *operation_list, int *a, int *b, int b_len);
char	*next_operation(char *operation_list);

#endif