/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/15 15:39:37 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
simply rotate the small list of numbers between 3-5
if it's closer to top, use RA else use RRA
*/
void	ra_rra_5(int *list, int length, int max)
{
	int	i;

	i = 0;
	while (list[i] != max)
		i++;
	if (i == 0)
		return ;
	if (i < (length / 2))
	{
		write(1, "ra\n", 3);
		ra_or_rb(list, length);
	}
	else
	{
		write(1, "rra\n", 4);
		rra_or_rrb(list, length);
	}
}

//shift up, the first element becomes the last
void	ra_or_rb(int *list, int length)
{
	int	temp;
	int	i;

	i = 0;
	temp = list[i];
	while (++i < length)
		list[i - 1] = list[i];
	list[i - 1] = temp;
}

//shift down, last element becomes the first
void	rra_or_rrb(int *list, int length)
{
	int	temp;

	temp = list[length -1];
	while (--length)
		list[length] = list[length -1];
	list[length] = temp;
}

/*
B stack rotate
if it's closer to top, use RB else use RRB
*/
void	rb_rrb_5(int *list, int b_length, int max)
{
	int	i;

	i = 0;
	while (list[i] != max)
		i++;
	if (i == 0)
		return ;
	if (i < (b_length / 2) + 1)
	{
		write(1, "rb\n", 3);
		ra_or_rb(list, b_length);
	}
	else
	{
		write(1, "rrb\n", 4);
		rra_or_rrb(list, b_length);
	}
}

//swap the first 2 elements
void	sa_or_sb(int *list, int argc)
{
	argc = list[0];
	list[0] = list[1];
	list[1] = argc;
}
