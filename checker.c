/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/11 19:35:16 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*operations;
	int		*operation_list;

	operation_list = (char *)malloc(1);
	*operation_list = 0;
	while (1)
	{
		operations = get_next_line(0);
		if (operations == NULL)
			break ;
		are_the_operations_valid(operations, operation_list);
		operation_list = ft_nm_strjoin(operation_list, operations);
	}
	argc = list_size(argc, argv);
	a = (int *)malloc((argc) * sizeof(int));
	b = (int *)malloc((argc) * sizeof(int));
	create_list(argc, a, argv);
	do_the_operations(operation_list, a, b, argc);
	if (list_is_in_order(a, argc))
		write(1, "\x1B[1;4;32mOK\n", 12);
	else
		write(1, "\x1B[1;4;31mKO\n", 12);
	love_you_norm_free(a, b, operation_list);
}

void	are_the_operations_valid(char *operation, char *operation_list)
{
	static char	*options[11] = {"sa\n", "ra\n", "rra\n", "pa\n", "sb\n",
		"rb\n", "rrb\n", "pb\n", "rrr\n", "ss\n", "rr\n"};
	int			i;
	
	i = 0;
	if ((ft_strlen(operation) == 3) || (ft_strlen(operation) == 4))
		while (11 > i)
			if (ft_strcmp(operation, options[i++]))
				return ;
	write(2, "\x1B[1;4;31mError\n", 15);
	free(operation_list);
	free(operation);
	exit(1);
}

void	do_the_operations(char *operation_list, int *a, int *b, int argc)
{
	const int	brgc = argc;
	static int	i = 0;
	char		*move;

	while (*operation_list)
	{
		move = next_operation(operation_list);
		if ((ft_strcmp(move, )))
	}
}

char	*next_operation(char *operation_list)
{
	static char	move[4];
	int			i;

	i = 0;
	while (operation_list[i] && operation_list[i] != '\n')
	{
		move[i] = operation_list[i];
		i++;
	}
	move[i] = 0;
	return (move);
}