/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:12 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/23 11:52:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
get the pivot number what I will call MID. While I've it's position compare the
stack elements to it, if they are smaller PB else RA and if no more, get the
next pivot number. Then sort the remaining 5 in A and sort back the rest to A
length of A decrese why B (i) incrase
*/
void	sort_bigger(int *a, int *b, int len)
{
	int	i;
	int	mid;
	int	a_len;

	a_len = len;
	i = 0;
	while (a_len > 5)
	{
		mid = pivot_finder(a + i, a_len, len);
		while (is_pivot_here(a + i, a_len, mid) && a_len > 5)
		{
			if (a[i] < mid)
			{
				write(1, "pb\n", 3);
				--a_len;
				b[a_len] = a[i];
				i++;
				continue ;
			}
			ra_or_rb(a + i, a_len);
			write(1, "ra\n", 3);
		}
	}
	sort_5(a + i, a_len);
	sort_to_a(b + a_len, len - a_len);
}

//goes thru the stack to find the pivot number
int	pivot_finder(int *stack, int a_len, int len)
{
	int	i;

	i = 0;
	while (i < a_len)
	{
		if (calculate_position(stack, stack[i], a_len, len))
			return (stack[i]);
		i++;
	}
	return (0);
}

/*
counts the elements in the stack that are smaller than the picked MID(PIVOT)
if this count equal to 1/3 or 1/5 of the stack then it will be the pivot.
*/
int	calculate_position(int *stack, int mid, int a_len, int len)
{
	int	smaller;
	int	i;

	i = 0;
	smaller = 0;
	while (i < a_len)
	{
		if (stack[i] < mid)
			smaller++;
		i++;
	}
	if (pick_divider(len, a_len, smaller) == 1)
		return (1);
	return (0);
}

//RRA the min numbers to top
void	sort_to_a(int *stack, int b_len)
{
	int	rra_min_from_bottom;
	int	i;
	int	small_numbers;

	i = 0;
	small_numbers = 0;
	rra_min_from_bottom = sort_b_to_a(stack, b_len, i, small_numbers);
	while (rra_min_from_bottom > 0)
	{
		write(1, "rra\n", 4);
		rra_min_from_bottom--;
	}
}

/*
rotate B to get MAX on top -> PA -> reapeat with next biggest number
if stack[i] = MAX, NEXT MAX or MIN, apply the correct operation, PA, SA or RA
*/
int	sort_b_to_a(int *stack, int b_len, int i, int j)
{
	static int		fd = 0;
	t_calculation	c;

	while (b_len > 0)
	{
		c.min = get_smallest_number(stack + i, b_len);
		c.max = get_biggest_number(stack + i, b_len);
		c.next = get_next_biggest_number(stack + i, b_len);
		rb_or_rrb(stack + i, b_len, c.max);
		if (stack[i] == c.max || (stack[i] == c.next && !fd)
			|| stack[i] == c.min)
		{
			write(1, "pa\n", 3);
			if (stack[i] == c.next && fd == 0)
				fd = 1;
			else if (fd && stack[i] == c.max)
				write(fd--, "sa\n", 3);
			else if (stack[i] == c.min && ++j)
				write(1, "ra\n", 3);
			--b_len;
			i++;
		}
	}
	return (j);
}
