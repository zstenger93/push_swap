/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/15 15:40:05 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*operation_list;

	operation_list = (char *)malloc(1);
	*operation_list = 0;
	operation_list = read_terminal(operation_list);
	argc = list_size(argc, argv);
	a = (int *) malloc((argc) * sizeof(int));
	b = (int *) malloc((argc) * sizeof(int));
	create_list(argc, a, argv);
	execute_operations(operation_list, a, b, argc);
	if (list_is_in_order(a, argc) == 1)
		write(1, "\x1B[32mOK\n", 8);
	else if (list_is_in_order(a, argc) == 0)
		printf("\x1B[32mKO\n");
	free(a);
	free(b);
	free(operation_list);
	exit(0);
}

//read the operations from the terminal, make and return a list out of it
char	*read_terminal(char *operation_list)
{
	char	*operation;

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
		error();
	}
}

//do the operations one by one from the list
void	execute_operations(char *operation_list, int *a, int *b, int b_len)
{
	char		*op;
	static int	i = 0;
	const int	a_len = b_len;

	while (*operation_list)
	{
		op = next_operation(operation_list);
		if ((ft_strcmp(op, "ra") || ft_strcmp(op, "rr")))
			ra_or_rb(a + i, a_len - i);
		if ((ft_strcmp(op, "rra") || ft_strcmp(op, "rrr")))
			rra_or_rrb(a + i, a_len - i);
		if ((ft_strcmp(op, "sa") || ft_strcmp(op, "ss")))
			sa_or_sb(a + i, 0);
		if (ft_strcmp(op, "pa") && b_len < a_len)
			a[--i] = b[b_len++];
		if (ft_strcmp(op, "pb") && i < a_len)
			b[--b_len] = a[i++];
		if ((ft_strcmp(op, "rb") || ft_strcmp(op, "rr")))
			ra_or_rb(b + b_len, a_len - b_len);
		if ((ft_strcmp(op, "sb") || ft_strcmp(op, "ss")))
			sa_or_sb(b + b_len, 0);
		if ((ft_strcmp(op, "rrb") || ft_strcmp(op, "rrr")))
			rra_or_rrb(b + b_len, a_len - b_len);
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
