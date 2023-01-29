/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/29 11:00:26 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	stack_len;

	if (argc < 2)
		return (0);
	is_argv_valid(argc, argv);
	stack_len = stack_size(argc, argv);
	a = (int *)malloc((stack_len) * sizeof(int));
	create_stack(stack_len, a, argv);
	b = (int *)malloc((stack_len) * sizeof(int));
	if (stack_is_in_order(a, stack_len) == false)
		speed_is_life(a, b, stack_len);
	free(a);
	free(b);
	return (0);
}

void	is_argv_valid(int argc, char **argv)
{
	int	j;
	size_t	i;
	size_t	space;

	j = 0;
	while (++j < argc)
	{
		if(ft_strlen(argv[j]) == 0)
			verror();
		i = 0;
		space = 0;
		while (i < ft_strlen(argv[j]))
		{
			if (argv[j][i] == ' ')
				space++;
			i++;
		}
		if (ft_strlen(argv[j]) == space)
			verror();
	}
}
