/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:16:27 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 11:28:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_smaller(int *a, int len)
{
	if (len == 2)
		write(1, "sa\n", 3);
	else if (len > 2 && len < 6)
	{
		if (len == 3)
			sort_3(a);
		else
			sort_5(a, len);
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

void	sort_5(int *a, int len)
{
	int	min;
	int	i;
	int	b_len;

	i = 0;
	b_len = len;
	while (len > 3)
	{
		min = get_smallest_number(a + i, len);
		ra_or_rra(a + i, len, min);
		if (a[i] == get_smallest_number(a + i, len))
		{
			write(1, "pb\n", 3);
			len--;
			i++;
		}
	}
	sort_3(a + i);
	while (b_len > len)
	{
		write(1, "pa\n", 3);
		b_len--;
	}
}
