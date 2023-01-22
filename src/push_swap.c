/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:15:04 by zstenger          #+#    #+#             */
/*   Updated: 2023/01/22 17:23:04 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	list_length;

	if (argc < 2)
		return (0);
	list_length = list_size(argc, argv);
	a = (int *)malloc((list_length) * sizeof(int));
	create_list(list_length, a, argv);
	b = (int *)malloc((list_length) * sizeof(int));
	if (list_is_in_order(a, list_length) == 0)
		speed_is_life(a, b, list_length);
	free(a);
	free(b);
	return (0);
}
