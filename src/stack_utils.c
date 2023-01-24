/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:16:49 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/24 17:00:16 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(int argc, char **argv)
{
	int			len;
	int			i;
	static int	j = 0;

	len = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
				i++;
			if (ft_isdigit(argv[j][i]))
				len++;
			else if (argv[j][i] != ' ' && argv[j][i] != '\t')
				return (ft_printf("\e[1;4;31mError!\e[0m\n"), 1);
			while (ft_isdigit(argv[j][i]))
				i++;
			if (argv[j][i] && argv[j][i] != ' ' && argv[j][i] != '\t')
				return (ft_printf("\e[1;4;31mError!\e[0m\n"), 1);
			while (argv[j][i] == '\t' || argv[j][i] == ' ')
				i++;
		}
	}
	return (len);
}

int	stack_is_in_order(int *stack, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (!stack[i])
			return (0);
		else if (stack[i - 1] > stack[i])
			return (false);
		i++;
	}
	return (true);
}

int	get_smallest_number(int *stack, int len)
{
	int	i;
	int	min;

	i = 0;
	min = *stack;
	while (i < len)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}

int	get_biggest_number(int *stack, int len)
{
	int	i;
	int	max;

	i = 0;
	max = *stack;
	while (i < len)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}

//if the 1st number == max then set next max to the second element
int	get_next_biggest_number(int *stack, int len)
{
	int	i;
	int	next_max;
	int	max;

	i = 0;
	max = get_biggest_number(stack, len);
	next_max = *stack;
	if (len > 1 && next_max == max)
		next_max = stack[1];
	while (i < len)
	{
		if (next_max < stack[i] && stack[i] != max)
			next_max = stack[i];
		i++;
	}
	return (next_max);
}
