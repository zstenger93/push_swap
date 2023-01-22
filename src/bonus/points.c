/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:12:56 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/22 14:20:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	points(int operation_count, int length)
{
	if (length == 2 || length == 3)
		two_or_three(operation_count, length);
	else if (length == 5)
		five(operation_count);
	else if (length == 100)
		hundred(operation_count);
	else if (length == 500)
		fivehundred(operation_count);
}

void	fivehundred(int operation_count)
{
	if (operation_count < 5500)
		ft_printf("\033[1;35mYou are genius!"
			"\n\033[1;35mPoints earned: \033[1;4;91m5\n");
	else if (operation_count < 7000)
		ft_printf("\033[1;35mNot bad, not bad!"
			"\n\033[1;35mPoints earned: \033[1;4;91m4\n");
	else if (operation_count < 8500)
		ft_printf("\033[1;35mAlright!"
			"\n\033[1;35mPoints earned: \033[1;4;91m3\n");
	else if (operation_count < 10000)
		ft_printf("\033[1;35mOoookay I guess!"
			"\n\033[1;35mPoints earned: \033[1;4;91m2\n");
	else if (operation_count < 11500)
		ft_printf("\033[1;35mI thought you can do better than this!"
			"\n\033[1;35mPoints earned: \033[1;4;91m1\n");
	else if (operation_count > 11500)
		ft_printf("\033[1;35mAre you serious? I"
			" can take a nap until this program does that amount of operations"
			"\n\033[1;35mPoints earned: \033[1;4;91m0\nYou Failed!\nKO");
}

void	hundred(int operation_count)
{
	if (operation_count < 700)
		ft_printf("\033[1;35mYou are Genius!"
			"\n\033[1;35mPoints earned: \033[1;4;91m5\n");
	else if (operation_count < 900)
		ft_printf("\033[1;35mNot bad, not bad!"
			"\n\033[1;35mPoints earned: \033[1;4;91m4\n");
	else if (operation_count < 1100)
		ft_printf("\033[1;35mAlright!"
			"\n\033[1;35mPoints earned: \033[1;4;91m3\n");
	else if (operation_count < 1300)
		ft_printf("\033[1;35mOoookay I guess!"
			"\n\033[1;35mPoints earned: \033[1;4;91m2\n");
	else if (operation_count < 1500)
		ft_printf("\033[1;35mGit gud man!"
			"\n\033[1;35mPoints earned: \033[1;4;91m1\n");
	else if (operation_count > 1500)
		ft_printf("\033[1;35mAre you serious? I"
			" can take a nap until this program does that amount of operations"
			"\n\033[1;35mPoints earned: \033[1;4;91m0\nYou Failed!\nKO");
}

void	five(int operation_count)
{
	if (operation_count <= 8)
		ft_printf("\033[1;35mNice sorting!\n");
	else if (operation_count <= 12)
		ft_printf("\033[1;35mNot bad, not bad!\n");
	else if (operation_count > 12)
		ft_printf("\033[1;35mAre you serious? I"
			" can take a nap until this program does that amount of operations"
			"\n\033[1;35mPoints earned: \033[1;4;91m0\nYou Failed!\nKO");
}

void	two_or_three(int operation_count, int length)
{
	if (length == 2)
	{
		if (operation_count == 1)
			ft_printf("\033[1;35mNice sorting!\n");
		else if (operation_count > 1)
			ft_printf("\033[1;35mAre you serious? I can take "
				"a nap until this program does that amount of operations"
				"\n\033[1;35mPoints earned: \033[1;4;91m0\nYou Failed!\nKO");
	}
	else if (length == 3)
	{
		if (operation_count <= 3)
			ft_printf("\033[1;35mNice sorting!\n");
		else if (operation_count > 12)
			ft_printf("\033[1;35mAre you serious? I can take "
				"a nap until this program does that amount of operations"
				"\n\033[1;35mPoints earned: \033[1;4;91m0\nYou Failed!\nKO");
	}
}
