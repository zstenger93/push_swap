/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:12 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/22 09:51:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
get the pivot number what I will call MID. While I've it's position compare the
list elements to it, if they are smaller PB else RA and if no more, get the
next pivot number. Then sort the remaining 5 in A and sort back the rest to A
length of A decrese why B (i) incrase
*/
void	sort_bigger(int *a, int *b, int length)
{
	int	i;
	int	mid;
	int	a_length;

	a_length = length;
	i = 0;
	while (a_length > 5)
	{
		mid = pivot_finder(a + i, a_length, length);
		while (is_pivot_here(a + i, a_length, mid) && a_length > 5)
		{
			if (a[i] < mid)
			{
				write(1, "pb\n", 3);
				b[--a_length] = a[i++];
				continue ;
			}
			ra_or_rb(a + i, a_length);
			write(1, "ra\n", 3);
		}
	}
	sort_5(a + i, a_length);
	sort_to_a(b + a_length, length - a_length);
}

//goes thru the list to find the pivot number
int	pivot_finder(int *list, int a_length, int length)
{
	int	i;

	i = 0;
	while (i < a_length)
	{
		if (calculate_position(list, list[i], a_length, length))
			return (list[i]);
		i++;
	}
	return (0);
}

/*
counts the elements in the list that are smaller than the picked MID(PIVOT)
if this count equal to 1/3 or 1/5 of the list then it will be the pivot.
*/
int	calculate_position(int *list, int mid, int a_length, int length)
{
	int	smaller;
	int	i;

	i = 0;
	smaller = 0;
	while (i < a_length)
	{
		if (list[i] < mid)
			smaller++;
		i++;
	}
	if (pick_divider(length, a_length, smaller) == 1)
		return (1);
	return (0);
}

int	pick_divider(int length, int a_length, int smaller)
{
	if (length > 250 && a_length > 250)
	{
		if (smaller == a_length / 7)
			return (1);
	}
	else if (length > 149 || a_length < 11)
	{
		if (smaller == a_length / 5)
			return (1);
	}
	else if (length < 150 && a_length > 10)
	{
		if (smaller == a_length / 3)
			return (1);
	}
	return (0);
}

/*
rotate B to get MAX on top -> PA -> reapeat with next biggest number
if list[i] = MAX, NEXT MAX or MIN, apply the correct operation, PA, SA or RA
J and FD for saving space when nothing left in B -> RRA the min numbers to top
*/
void	sort_to_a(int *list, int b_length)
{
	static int		i = 0;
	static int		j = 0;
	static int		fd = 0;
	t_calculation	c;

	while (b_length > 0)
	{
		c.min = get_smallest_number(list + i, b_length);
		c.max = get_biggest_number(list + i, b_length);
		c.next = get_next_biggest_number(list + i, b_length);
		rb_or_rrb(list + i, b_length, c.max);
		if (list[i] == c.max || (list[i] == c.next && !fd) || list[i] == c.min)
		{
			write(1, "pa\n", 3);
			if (list[i] == c.next && fd == 0)
				fd = 1;
			else if (fd && list[i] == c.max)
				write(fd--, "sa\n", 3);
			else if (list[i] == c.min)
				write(++j * 0 + 1, "ra\n", 3);
			i += (--b_length * 0) + 1;
		}
	}
	while (j--)
		write(1, "rra\n", 4);
}
