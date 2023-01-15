/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:12 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/15 10:22:31 by zstenger         ###   ########.fr       */
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
		mid = pivot_finder(a + i, b_length, length);
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

//goes thru the list to find the pivot number I will call as MID
int	pivot_finder(int *list, int b_length, int length)
{
	int	i;

	i = 0;
	while (i < b_length)
	{
		if (calculation(list, list[i], b_length, length))
			return (list[i]);
		i++;
	}
	return (0);
}

/*
counts the elements in the list that are smaller than the current MID
if this count equal to 1/2 or 1/5 of the list then it will be picked as pivot
kinda random number 1/2 or 1/5 of the way thru the list
not the most efficient coz now we pick a random number but cannot
figure out other way.
the best would be to pick middle number of the ordered list
*/
int	calculation(int *list, int mid, int b_length, int length)
{
	int	smaller;
	int	i;

	i = 0;
	smaller = 0;
	while (i < b_length)
	{
		if (list[i] < mid)
			smaller++;
		i++;
	}
	if (length < 157)
	{
		if (smaller == b_length / 3)
			return (1);
	}
	else if (length > 156)
	{
		if (smaller == b_length / 5)
			return (1);
	}
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
rotate B until the biggest number will be on top then push it to A
reapeat with next biggest number
if the current element of the list is equal to MAX, NEXT MAX or MIN,
apply the correct operation, PA, SA, RA
j and is for saving space fd will be always 1 to print the operations
the last while loop when there is nothing left in B we will put the
remaining min numbers from the bottom of A to the top
(also for saving private ryan, i mean space..)
*/
void	sort_to_a(int *list, int b_length)
{
	static int		i = 0;
	static int		j = 0;
	static int		is = 0;
	t_calculation	c;

	while (b_length > 0)
	{
		c.min = get_smallest_number(list + i, b_length);
		c.max = get_biggest_number(list + i, b_length);
		c.next = get_next_biggest_number(list + i, b_length);
		rotate_b(list + i, b_length, c.max);
		if (list[i] == c.max || (list[i] == c.next && !is) || list[i] == c.min)
		{
			write(1, "pa\n", 3);
			if (list[i] == c.next && is == 0)
				is = 1;
			else if (is && list[i] == c.max)
				write(is--, "sa\n", 3);
			else if (list[i] == c.min)
				write(++j * 0 + 1, "ra\n", 3);
			i += (--b_length * 0) + 1;
		}
	}
	while (j--)
		write(1, "rra\n", 4);
}
