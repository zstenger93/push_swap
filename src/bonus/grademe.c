/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:57:26 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 11:35:24 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	grademe(int *stack, char *operation_list, int len)
{
	if (stack_is_in_order(stack, len) == 1)
	{
		result(operation_list, len);
		write(1, "\x1B[32mOK\n", 8);
	}
	else if (stack_is_in_order(stack, len) == 0)
		write(1, "\x1B[31mKO\n", 8);
}

void	result(char *opl, int len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (opl[k] != '\0')
	{
		while (opl[k] == ' ' || opl[k] == '\t' || opl[k] == '\n')
			k++;
		if (opl[k] >= 'a' && opl[k] <= 'z')
		{
			i++;
			k++;
		}
		while (opl[k] >= 'a' && opl[k] <= 'z' && opl[k] != '\n')
			k++;
	}
	if (len > 0)
	{
		ft_printf("\x1B[1;4;91mYour operation count is:\n"
			"\033[0;39m\x1B[1;36m%d\n", i);
		points(i, len);
	}
}
