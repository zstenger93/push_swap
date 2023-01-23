/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_earned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 16:21:20 by zstenger         ###   ########.fr       */
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
		ft_printf("\033[1;35m|      Congratulations!!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m5\033[0;39m      |");
	else if (operation_count < 7000)
		ft_printf("\033[1;35m|      Not bad, not bad!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m4\033[0;39m      |");
	else if (operation_count < 8500)
		ft_printf("\033[1;35m|      It could be less!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m3\033[0;39m      |");
	else if (operation_count < 10000)
		ft_printf("\033[1;35m|      Ooookay I gueess!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m2\033[0;39m      |");
	else if (operation_count < 11500)
		ft_printf("\033[1;35m|    My grandma is faster!   |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m1\033[0;39m      |");
	else if (operation_count > 11500)
		ft_printf("\033[1;35mAre you serious? I"
			" can take a nap until this program does that amount of operations"
			"\n\033[1;35m   Points earned: \033[1;4;91m0\nYou Failed!\nKO");
}

void	hundred(int operation_count)
{
	if (operation_count < 700)
		ft_printf("\033[1;35m|      Congratulations!!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m5\033[0;39m      |");
	else if (operation_count < 900)
		ft_printf("\033[1;35m|      Not bad, not bad!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m4\033[0;39m      |");
	else if (operation_count < 1100)
		ft_printf("\033[1;35m|      It could be less!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m3\033[0;39m      |");
	else if (operation_count < 1300)
		ft_printf("\033[1;35m|      Ooookay I gueess!     |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m2\033[0;39m      |");
	else if (operation_count < 1500)
		ft_printf("\033[1;35m|    My grandma is faster!   |\n"
			"\033[1;35m|      Points earned: \033[1;4;91m1\033[0;39m      |");
	else if (operation_count > 1500)
		ft_printf("\033[1;35mAre you serious? I"
			" can take a nap until this program does that amount of operations"
			"\n\033[1;35m   Points earned: \033[1;4;91m0\nYou Failed!\nKO");
}

void	five(int operation_count)
{
	if (operation_count <= 8)
		ft_printf("\033[1;35m|        Nice sorting!       |\n");
	else if (operation_count <= 12)
		ft_printf("\033[1;35m|       Not bad, not bad!      |\n");
	else if (operation_count > 12)
		ft_printf("\033[1;35mAre you serious? I"
			" can take a nap until this program does that amount of operations"
			"\n\033[1;35m   Points earned: \033[1;4;91m0\nYou Failed!\nKO");
}

void	two_or_three(int operation_count, int len)
{
	if (len == 2)
	{
		if (operation_count == 1)
			ft_printf("\033[1;35m|        Nice sorting!       |\n");
		else if (operation_count > 1)
			ft_printf("\033[1;35mAre you serious? I can take "
				"a nap until this program does that amount of operations"
				"\n\033[1;35m   Points earned: \033[1;4;91m0\nYou Failed!\nKO");
	}
	else if (len == 3)
	{
		if (operation_count <= 3)
			ft_printf("\033[1;35m|        Nice sorting!       |\n");
		else if (operation_count > 12)
			ft_printf("\033[1;35mAre you serious? I can take "
				"a nap until this program does that amount of operations"
				"\n\033[1;35m   Points earned: \033[1;4;91m0\nYou Failed!\nKO");
	}
}
