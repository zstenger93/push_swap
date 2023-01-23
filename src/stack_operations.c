/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 11:32:38 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_or_rra(int *stack, int len, int max)
{
	int	i;

	i = 0;
	while (stack[i] != max)
		i++;
	if (i == 0)
		return ;
	if (i < (len / 2))
	{
		write(1, "ra\n", 3);
		ra_or_rb(stack, len);
	}
	else
	{
		write(1, "rra\n", 4);
		rra_or_rrb(stack, len);
	}
}

//shift up, the first element becomes the last
void	ra_or_rb(int *stack, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack[i];
	while (++i < len)
		stack[i - 1] = stack[i];
	stack[i - 1] = temp;
}

//shift down, last element becomes the first
void	rra_or_rrb(int *stack, int len)
{
	int	temp;

	temp = stack[len -1];
	while (--len)
		stack[len] = stack[len -1];
	stack[len] = temp;
}

void	rb_or_rrb(int *stack, int b_len, int max)
{
	int	i;

	i = 0;
	while (stack[i] != max)
		i++;
	if (i == 0)
		return ;
	if (i < (b_len / 2) + 1)
	{
		write(1, "rb\n", 3);
		ra_or_rb(stack, b_len);
	}
	else
	{
		write(1, "rrb\n", 4);
		rra_or_rrb(stack, b_len);
	}
}

void	sa_or_sb(int *stack, int swap)
{
	swap = stack[0];
	stack[0] = stack[1];
	stack[1] = swap;
}
