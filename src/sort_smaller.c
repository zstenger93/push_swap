/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:16:27 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/18 11:43:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_smaller(int *a, int length)
{
	if (length == 2)
		write(1, "sa\n", 3);
	else if (length > 2 && length < 6)
	{
		if (length == 3)
			sort_3(a);
		else
			sort_5(a, length);
	}
}

void	sort_3(int *a)
{
	int	first;
	int	second;
	int	third;

	first = a[0];
	second = a[1];
	third = a[2];
	if ((first > second) && (first < third) && (second < third))
		write(1, "sa\n", 3);
	else if ((first > second) && (first > third) && (second > third))
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if ((first > second) && (first > third) && (second < third))
		write(1, "ra\n", 3);
	else if ((first < second) && (first < third) && (second > third))
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
	}
	else if ((first < second) && (first > third) && (second > third))
		write(1, "rra\n", 4);
}

void	sort_5(int *a, int length)
{
	int	min;
	int	i;
	int	temp_length;

	i = 0;
	temp_length = length;
	while (length > 3)
	{
		min = get_smallest_number(a + i, length);
		ra_or_rra(a + i, length, min);
		if (a[i] == get_smallest_number(a + i, length))
		{
			write(1, "pb\n", 3);
			length--;
			i++;
		}
	}
	sort_3(a + i);
	while (temp_length-- > length)
		write(1, "pa\n", 3);
}
