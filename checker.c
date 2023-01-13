/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/13 19:16:13 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	// int	*a;
	// int	*b;
	char	*operation_list;


	if (argc < 2)
	 	return (0);
	else
		operation_list = read_terminal(argc, argv);
	printf("%s", operation_list);
	// argc = list_size(argc, argv);
	// a = (int *) malloc((argc) * sizeof(int));
	// b = (int *) malloc((argc) * sizeof(int));
	// create_list(argc, a, argv);
	// execute_operations(operation_list, a, b, argc);
	// if (list_is_in_order(a, argc))
	// 	write(1, "\x1B[32mOK\n", 8);
	// else
	// 	write(1, "\x1B[31mKO\n", 8);
	exit(0);
}

char	*read_terminal(int argc, char **argv)
{
	char	*operation;
	char	*operation_list;

	operation_list = (char *)malloc(1);
	*operation_list = 0;
	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		// is_valid_operation(operation, operation_list);
		operation_list = ft_gnl_strjoin(operation_list, operation);
	}
	return (operation_list);
}