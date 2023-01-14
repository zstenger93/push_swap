/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/14 19:06:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	char	*operation_list;


	operation_list = (char *)malloc(1);
	*operation_list = 0;
	operation_list = read_terminal(argc, argv, operation_list);
	printf("%s", operation_list);
	argc = list_size(argc, argv);
	a = (int *) malloc((argc) * sizeof(int));
	b = (int *) malloc((argc) * sizeof(int));
	create_list(argc, a, argv);
	execute_operations(operation_list, a, b, argc);
	int i = 0;
	while (i < argc)
		printf("%d ", a[i++]);
	if (list_is_in_order(a, argc) == 1)
		write(1, "\x1B[32mOK\n", 8);
	else if (list_is_in_order(a, argc) == 0)
		printf("\nWHAT THE FUCK\n");
	free(a);
	free(b);
	free(operation_list);
	exit(0);
}

char	*read_terminal(int argc, char **argv, char *operation_list)
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

void	is_valid_operation(char *operation, char *operation_list)
{
	static char	*valid_operations[11] = {"sa\n", "ra\n", "rra\n", "pa\n",
		"sb\n", "rb\n", "rrb\n", "pb\n", "rrr\n", "ss\n", "rr\n"};
	int			i;

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

void	execute_operations(char *operation_list, int *a, int *b, int b_len)
{
	char		*op;
	static int	i;
	const int	a_len = b_len;

	while (*operation_list)
	{
		op = next_operation(operation_list);
		if ((ft_strcmp(op, "ra") || ft_strcmp(op, "rr")) && i < a_len - 1)
			rotate(a + i, a_len - i);
		if ((ft_strcmp(op, "rra") || ft_strcmp(op, "rrr")) && i < a_len - 1)
			reverse_rotate(a + i, a_len - i);
		if ((ft_strcmp(op, "sa") || ft_strcmp(op, "ss")) && i < a_len - 1)
			sa_or_sb(a + i, 0);
		if (ft_strcmp(op, "pa") && b_len < a_len)
			a[--i] = b[b_len++];
		if (ft_strcmp(op, "pb") && i < a_len)
			b[--b_len] = a[i++];
		if ((ft_strcmp(op, "rb") || ft_strcmp(op, "rr")) && b_len < a_len - 1)
			rotate(b + b_len, a_len - b_len);
		if ((ft_strcmp(op, "sb") || ft_strcmp(op, "ss")) && b_len < a_len - 1)
			sa_or_sb(b + b_len, 0);
		if ((ft_strcmp(op, "rrb") || ft_strcmp(op, "rrr")) && b_len < a_len - 1)
			reverse_rotate(b + b_len, a_len - b_len);
		operation_list += ft_strlen(op) + 1;
	}
}

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
