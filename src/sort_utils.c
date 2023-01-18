/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/18 11:44:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_or_rra(int *list, int length, int max)
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

void	rb_or_rrb(int *list, int b_length, int max)
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

void	sa_or_sb(int *list, int swap)
{
	swap = list[0];
	list[0] = list[1];
	list[1] = swap;
}
