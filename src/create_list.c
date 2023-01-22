/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:29:31 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/22 18:12:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
first loop goes thru the arguments one by one
second loop goes thru each character of the current argument
convert it with atoi and assign it to the current element of the list
give a pointer to the start of the string 
*/
void	create_list(int length, int *list_a, char **argv)
{
	int	i;
	int	index;
	int	j;

	j = 0;
	index = 0;
	while (++j && index < length)
	{
		i = 0;
		while (argv[j][i])
		{
			while (argv[j][i] == ' ' || argv[j][i] == '+')
				i++;
			if (ft_isdigit(argv[j][i]) || argv[j][i] == '-')
				list_a[index++] = ft_atoi2(&argv[j][i], list_a);
			if (argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			while (ft_isdigit(argv[j][i]))
				i++;
			while (argv[j][i] == ' ' || argv[j][i] == '\t')
				i++;
		}
	}
	check_for_doubles(list_a, length);
}

void	check_for_doubles(int *list, int length)
{
	int	i;
	int	j;

	j = 0;
	while (j < length)
	{
		i = j + 1;
		while (i < length)
		{
			if (list[j] == list[i])
				error(list);
			i++;
		}
		j++;
	}
}

void	speed_is_life(int *a, int *b, int length)
{
	if (length > 1 && length < 6)
		sort_smaller(a, length);
	else if (length > 5)
		sort_bigger(a, b, length);
}

//are there smaller numbers than the pivot?
int	is_pivot_here(int *list, int a_length, int mid)
{
	int	i;

	i = 0;
	while (i < a_length)
	{
		if (list[i] < mid)
			return (1);
		i++;
	}
	return (0);
}

int	pick_divider(int length, int a_length, int smaller)
{
	if (length > 250 && a_length > 250)
	{
		if (smaller == a_length / 7)
			return (1);
	}
	else if (length > 149 || a_length < 11)
	{
		if (smaller == a_length / 5)
			return (1);
	}
	else if (length < 150 && a_length > 10)
	{
		if (smaller == a_length / 3)
			return (1);
	}
	return (0);
}
