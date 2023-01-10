/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:21 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/10 17:40:36 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_calculation
{
	int	min;
	int	next;
	int	max;
}t_calculation;

int		list_size(int argc, char **argv);
void	create_list(int length, int *list_a, char **argv);
void	check_for_doubles(int *list, int length);
int		list_is_in_order(int *list, int length);
void	speed_is_life(int *a, int *b, int length);
void	sort_smaller(int *a, int length);
void	sort_3(int *a);
void	sort_5(int *a, int length);
void	rotate_5(int *list, int length, int max);
void	rotate(int *list, int length);
void	reverse_rotate(int *list, int length);
void	error(void);

int		get_smallest_number(int *list, int length);
int		get_biggest_number(int *list, int length);
int		get_next_biggest_number(int *list, int length);

void	sort_bigger(int *a, int *b, int length);

int		pivot_finder(int *list, int length);
int		calculation(int *list, int mid, int length);
int		is_pivot_here(int *list, int length, int mid);

void	sort_to_a(int *list, int b_length);
void	rotate_b(int *list, int b_length, int max);

#endif