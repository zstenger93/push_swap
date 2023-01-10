/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:12 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/10 21:44:49 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
bigger list sorting
get the pivot number what I will call MID
while I have the position of the PIVOT(MID) compare the list elements to it,
if they are smaller use PB(push to B) else RA(rotate A)
after we are done with pushing to B, sort the remaining 5 in A with sort_5
then sort back the rest with sort_to_a
*/
void	sort_bigger(int *a, int *b, int length)
{
	int	i;
	int	mid;
	int	b_length;

	b_length = length;
	i = 0;
	while (b_length > 5)
	{
		mid = pivot_finder(a + i, b_length);
		while (is_pivot_here(a + i, b_length, mid) && b_length > 5)
		{
			if (a[i] < mid)
			{
				write(1, "pb\n", 3);
				b[--b_length] = a[i++];
				continue ;
			}
			rotate(a + i, b_length);
			write(1, "ra\n", 3);
		}
	}
	sort_5(a + i, b_length);
	sort_to_a(b + b_length, length - b_length);
}

//get the pivot number
int	pivot_finder(int *list, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (calculation(list, list[i], length))
			return (list[i]);
		i++;
	}
	return (0);
}

//check if the pivot number is correct
int	calculation(int *list, int mid, int length)
{
	int	smaller;
	int	i;

	i = 0;
	smaller = 0;
	while (i < length)
	{
		if (list[i] < mid)
			smaller++;
		i++;
	}
	if (smaller == length / 3)
		return (1);
	return (0);
}

//check if the element of the list is the pivot number or not
int	is_pivot_here(int *list, int length, int mid)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (list[i] < mid)
			return (1);
		i++;
	}
	return (0);
}

/*
calc the smallest number
calc the biggest number
calc the next biggest number
sort back the numbers from B to A, one biggest number at a time
rotate B until the biggest number will be on top then push it to A
reapeat with next biggest number
if the current element of the list is equal to MAX, NEXT MAX or MIN,
apply the correct operation, PA, SA, RA if none of them, RRA
*/
void	sort_to_a(int *list, int b_length)
{
	static int		i = 0;
	static int		j = 0;
	static int		is = 0;
	t_calculation	calc;

	calc.min = get_smallest_number(list + i, b_length);
	calc.max = get_biggest_number(list + i, b_length);
	calc.next = get_next_biggest_number(list + i, b_length);
	rotate_b(list + i, b_length, calc.max);
	if (list[i] == calc.max || (list[i] == calc.next && !is)
		|| list[i] == calc.min)
	{
		write(1, "pa\n", 3);
		if (list[i] == calc.next && is == 0)
			is = 1;
		else if (is && list[i] == calc.max)
			write(is--, "sa\n", 3);
		else if (list[i] == calc.min)
			write(++j * 0 + 1, "ra\n", 3);
		i += (--b_length * 0) + 1;
	}
	while (j--)
		write(1, "rra\n", 4);
}
