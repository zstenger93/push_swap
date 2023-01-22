/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/22 13:24:41 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*operation_list;

	if (argc < 2)
		return (0);
	operation_list = (char *)malloc(1);
	*operation_list = 0;
	argc = list_size(argc, argv);
	operation_list = read_terminal(operation_list);
	a = (int *) malloc((argc) * sizeof(int));
	b = (int *) malloc((argc) * sizeof(int));
	create_list(argc, a, argv);
	if (list_is_in_order(a, argc) == 0)
		execute_operations(operation_list, a, b, argc);
	grademe(a, operation_list, argc);
	free(operation_list);
	free(a);
	free(b);
	return (0);
}

//read the operations from standard input, make and return a list out of it
char	*read_terminal(char *operation_list)
{
	char			*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		is_valid_operation(operation, operation_list);
		operation_list = ft_gnl_strjoin(operation_list, operation);
	}
	return (operation_list);
}

//check each operation if it's correct
void	is_valid_operation(char *operation, char *operation_list)
{
	static char	*valid_operations[11] = {"sa\n", "ra\n", "rra\n", "pa\n",
		"sb\n", "rb\n", "rrb\n", "pb\n", "rrr\n", "ss\n", "rr\n"};
	int			i;

	i = 0;
	if ((ft_strlen(operation) == 3) || ft_strlen(operation) == 4)
	{
		while (i < 11)
			if (ft_strcmp(operation, valid_operations[i++]))
				return ;
	}
	else
	{
		free(operation_list);
		free(operation);
		ft_printf("\e[1;4;31mError!\e[0m\n");
		exit(1);
	}
}

/*
executing the operations one by one on the lists and changing the length
of the arrays depending on if it's PA or PB
pa - b index decrese a index incrase
pb - a index decrese b index incrase
*/
void	execute_operations(char *operation_list, int *a, int *b, int a_len)
{
	char		*op;
	static int	i = 0;
	const int	length = a_len;

	while (*operation_list)
	{
		op = next_operation(operation_list);
		if (ft_strcmp(op, "ra") || ft_strcmp(op, "rr"))
			ra_or_rb(a + i, length - i);
		if (ft_strcmp(op, "rra") || ft_strcmp(op, "rrr"))
			rra_or_rrb(a + i, length - i);
		if (ft_strcmp(op, "sa") || ft_strcmp(op, "ss"))
			sa_or_sb(a + i, 0);
		if (ft_strcmp(op, "pa"))
			a[--i] = b[a_len++];
		if (ft_strcmp(op, "pb"))
			b[--a_len] = a[i++];
		if (ft_strcmp(op, "rb") || ft_strcmp(op, "rr"))
			ra_or_rb(b + a_len, length - a_len);
		if (ft_strcmp(op, "sb") || ft_strcmp(op, "ss"))
			sa_or_sb(b + a_len, 0);
		if (ft_strcmp(op, "rrb") || ft_strcmp(op, "rrr"))
			rra_or_rrb(b + a_len, length - a_len);
		operation_list += ft_strlen(op) + 1;
	}
}

//get the next operation form the operation list
char	*next_operation(char *operation_list)
{
	static char	oprs[4];
	int			i;

	i = 0;
	while (operation_list[i] && operation_list[i] != '\n')
	{
		oprs[i] = operation_list[i];
		i++;
	}
	oprs[i] = 0;
	return (oprs);
}
