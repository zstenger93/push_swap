/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:58 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/10 17:35:35 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

//rotate the b stack 
void	rotate_b(int *list, int b_length, int max)
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
		rotate(list, b_length);
	}
	else
	{
		write(1, "rrb\n", 4);
		reverse_rotate(list, b_length);
	}
}

//simply rotate the small list of numbers between 3-5
void	rotate_5(int *list, int length, int max)
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
		rotate(list, length);
	}
	else
	{
		write(1, "rra\n", 4);
		reverse_rotate(list, length);
	}
}

//rotate numbers
void	rotate(int *list, int length)
{
	int	temp;
	int	i;

	i = 0;
	temp = list[i];
	while (++i < length)
		list[i - 1] = list[i];
	list[i - 1] = temp;
}

//reverse rotate numbers
void	reverse_rotate(int *list, int length)
{
	int	temp;

	temp = list[length -1];
	while (--length)
		list[length] = list[length -1];
	list[length] = temp;
}
