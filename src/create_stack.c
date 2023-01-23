/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:45:06 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 14:07:22 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
first loop goes thru the arguments one by one
second loop goes thru each character of the current argument
convert it with atoi and assign it to the current element of the stack
give a pointer to the start of the string 
*/
void	create_stack(int len, int *stack_a, char **argv)
{
	int	i;
	int	index;
	int	j;

	j = 0;
	index = 0;
	while (++j && index < len)
	{
		i = 0;
		while (argv[j][i])
		{
			while (argv[j][i] == ' ' || argv[j][i] == '+')
				i++;
			if (ft_isdigit(argv[j][i]) || argv[j][i] == '-')
				stack_a[index++] = ft_atoi2(&argv[j][i], stack_a);
			if (argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			while (ft_isdigit(argv[j][i]))
				i++;
			while (argv[j][i] == ' ' || argv[j][i] == '\t')
				i++;
		}
	}
	check_for_doubles(stack_a, len);
}

void	check_for_doubles(int *stack, int len)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = j + 1;
		while (i < len)
		{
			if (stack[j] == stack[i])
				error(stack);
			i++;
		}
		j++;
	}
}

void	speed_is_life(int *a, int *b, int len)
{
	if (len > 1 && len < 6)
		sort_smaller(a, len);
	else if (len > 5)
		sort_bigger(a, b, len);
}

//are there smaller numbers than the pivot?
int	is_pivot_here(int *stack, int a_len, int pivot)
{
	int	i;

	i = 0;
	while (i < a_len)
	{
		if (stack[i] < pivot)
			return (true);
		i++;
	}
	return (false);
}

int	pick_divider(int len, int a_len, int smaller)
{
	if (len > 250 && a_len > 250)
	{
		if (smaller == a_len / 7)
			return (true);
	}
	else if (len > 149 || a_len < 11)
	{
		if (smaller == a_len / 5)
			return (true);
	}
	else if (len < 150 && a_len > 10)
	{
		if (smaller == a_len / 3)
			return (true);
	}
	return (false);
}
