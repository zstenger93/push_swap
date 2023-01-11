/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/11 18:33:05 by zstenger         ###   ########.fr       */
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
		write(1, "\x1B[32mOK\n", 8);
	else
		write(1, "\x1B[31mKO\n", 8);
	//free everything here
}
