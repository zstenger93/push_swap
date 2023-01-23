/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 11:34:21 by zstenger         ###   ########.fr       */
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
	stack_len = stack_size(argc, argv);
	a = (int *)malloc((stack_len) * sizeof(int));
	create_stack(stack_len, a, argv);
	b = (int *)malloc((stack_len) * sizeof(int));
	if (stack_is_in_order(a, stack_len) == 0)
		speed_is_life(a, b, stack_len);
	free(a);
	free(b);
	return (0);
}
