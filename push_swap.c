/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/10 17:50:11 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
if there are no arguments, only the executable return error
malloc memory for A and B with the length of the input
create the list A from the input if the input is correct
check if the list is already in order if so quit
speed is life -> choose the way of sorting base on the length of the list
*/
int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	list_length;

	if (argc < 2)
		error();
	list_length = list_size(argc, argv);
	a = (int *)malloc((list_length) * sizeof(int));
	b = (int *)malloc((list_length) * sizeof(int));
	create_list(list_length, a, argv);
	if (list_is_in_order(a, list_length))
		list_length--;
	speed_is_life(a, b, list_length);
	free(a);
	free(b);
}

void	speed_is_life(int *a, int *b, int length)
{
	if (length > 1 && length < 6)
		sort_smaller(a, length);
	else if (length > 5)
		sort_bigger(a, b, length);
}

/*
make the list using atoi and check for dubles
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
			if (ft_isdigit(argv[j][i]) || argv[j][i] == '-'
				|| argv[j][i] == '+')
				list_a[index++] = ft_atoi(&argv[j][i]);
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
				error();
			i++;
		}
		j++;
	}
}
