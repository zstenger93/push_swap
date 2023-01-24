/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_earned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/24 14:30:10 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	points(int operation_count, int len)
{
	if (len == 2 || len == 3)
		two_or_three(operation_count, len);
	else if (len == 5)
		five(operation_count);
	else if (len == 100)
		hundred(operation_count);
	else if (len == 500)
		fivehundred(operation_count);
}

void	fivehundred(int operation_count)
{
	if (operation_count < 5500)
		ft_printf("\033[1;35m\t\t|      Congratulations!!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m5\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 7000)
		ft_printf("\033[1;35m\t\t|      Not bad, not bad!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m4\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 8500)
		ft_printf("\033[1;35m\t\t|      It could be less!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m3\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 10000)
		ft_printf("\033[1;35m\t\t|      Ooookay I gueess!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m2\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 11500)
		ft_printf("\033[1;35m\t\t|    My grandma is faster!   |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m1\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count > 11500)
		ft_printf("\033[1;31m\t\t|      Sorry you failed!     |");
}

void	hundred(int operation_count)
{
	if (operation_count < 700)
		ft_printf("\033[1;35m\t\t|      Congratulations!!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m5\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 900)
		ft_printf("\033[1;35m\t\t|      Not bad, not bad!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m4\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 1100)
		ft_printf("\033[1;35m\t\t|      It could be less!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m3\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 1300)
		ft_printf("\033[1;35m\t\t|      Ooookay I gueess!     |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m2\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count < 1500)
		ft_printf("\033[1;35m\t\t|    My grandma is faster!   |\n\t\t"
			"\033[1;35m|      Points earned: \033[1;4;91m1\033[0;39m"
			"\033[1;35m      |");
	else if (operation_count > 1500)
		ft_printf("\033[1;35m\t\t|      Sorry you failed!     |");
}

void	five(int operation_count)
{
	if (operation_count <= 8)
		ft_printf("\033[1;35m\t\t|        Nice sorting!       |");
	else if (operation_count <= 12)
		ft_printf("\033[1;35m\t\t|      Not bad, not bad!     |");
	else if (operation_count > 12)
		ft_printf("\033[1;31m\t\t|      Sorry you failed!     |");
}

void	two_or_three(int operation_count, int len)
{
	if (len == 2)
	{
		if (operation_count <= 1)
			ft_printf("\033[1;35m\t\t|        Nice sorting!       |");
		else if (operation_count > 1)
			ft_printf("\033[1;31m\t\t|      Sorry you failed!     |");
	}
	else if (len == 3)
	{
		if (operation_count <= 3)
			ft_printf("\033[1;35m\t\t|        Nice sorting!       |");
		else if (operation_count > 3)
			ft_printf("\033[1;31m\t\t|      Sorry you failed!     |");
	}
}
