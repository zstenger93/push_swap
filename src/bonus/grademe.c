/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:57:26 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 16:34:30 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	grademe(int *stack, char *operation_list, int len)
{
	if (stack_is_in_order(stack, len) == true)
	{
		result(operation_list, len);
		ft_printf("\n\x1B[1;32m|_____________OK_____________|\n");
	}
	else if (stack_is_in_order(stack, len) == false)
		write(1, "          \x1B[1;31mKO\n", 18);
}

void	result(char *opl, int len)
{
	int	operation_count;
	int	k;

	operation_count = 0;
	k = 0;
	while (opl[k] != '\0')
	{
		while (opl[k] == ' ' || opl[k] == '\t' || opl[k] == '\n')
			k++;
		if (opl[k] >= 'a' && opl[k] <= 'z')
		{
			operation_count++;
			k++;
		}
		while (opl[k] >= 'a' && opl[k] <= 'z' && opl[k] != '\n')
			k++;
	}
	output(operation_count, len);
}

void	output(int operation_count, int len)
{
	if (len > 0)
	{
		if (len == 500 || len == 100 || len == 5 || len == 3 || len == 2)
			write(1, "______________________________\n", 31);
		if (len == 500)
		{
			ft_printf("\x1B[1;4;91m|  Your operation count is:  |\033[0;39m\n"
				"|            \x1B[1;36m%d            |\n", operation_count);
			points(operation_count, len);
		}
		else if (len == 100)
		{
			ft_printf("\x1B[1;4;91m|  Your operation count is:  |\033[0;39m\n"
				"|             \x1B[1;36m%d            |\n", operation_count);
			points(operation_count, len);	
		}
		else if (len == 5 || len == 3 || len == 2)
			output2(operation_count, len);
	}
}

void	output2(int operation_count, int len)
{

	if (len == 5 && operation_count > 9)
	{
		ft_printf("\x1B[1;4;91m|  Your operation count is:  |\033[0;39m\n"
			"|             \x1B[1;36m%d             |\n", operation_count);
		points(operation_count, len);
	}
	else if (len == 5 && operation_count < 10)
	{
		ft_printf("\x1B[1;4;91m|  Your operation count is:  |\033[0;39m\n"
			"|             \x1B[1;36m%d              |\n", operation_count);
		points(operation_count, len);
		
	}
	else if (len == 3 || len == 2)
	{
		ft_printf("\x1B[1;4;91m|  Your operation count is:  |\033[0;39m\n"
			"|             \x1B[1;36m%d              |\n", operation_count);
		points(operation_count, len);
	}
}