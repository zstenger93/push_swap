/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:16:49 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/14 18:51:10 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
get the length of the list while calculating only numbers,
not the -, +, space, tab, and if it's none of them, return an error
*/
int	list_size(int argc, char **argv)
{
	int			length;
	int			i;
	static int	j = 0;

	length = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
				i++;
			if (ft_isdigit(argv[j][i]))
				length++;
			else if (argv[j][i] != ' ' && argv[j][i] != '\t')
				error();
			while (ft_isdigit(argv[j][i]))
				i++;
			if (argv[j][i] && argv[j][i] != ' ' && argv[j][i] != '\t')
				error();
			while (argv[j][i] == '\t' || argv[j][i] == ' ')
				i++;
		}
	}
	return (length);
}

int	list_is_in_order(int *list, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (list[i - 1] > list[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_smallest_number(int *list, int length)
{
	int	i;
	int	min;

	i = 0;
	min = *list;
	while (length--)
	{
		if (min > list[i])
			min = list[i];
		i++;
	}
	return (min);
}

int	get_biggest_number(int *list, int length)
{
	int	i;
	int	max;

	i = 0;
	max = *list;
	while (length--)
	{
		if (max < list[i])
			max = list[i];
		i++;
	}
	return (max);
}

int	get_next_biggest_number(int *list, int length)
{
	int	i;
	int	next_max;
	int	max;

	i = 0;
	max = get_biggest_number(list, length);
	next_max = *list;
	if (next_max == max)
		next_max = list[1];
	while (length--)
	{
		if (next_max < list[i] && list[i] != max)
			next_max = list[i];
		i++;
	}
	return (next_max);
}
