/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:07:33 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:51:58 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_butterfly(t_list **stack_a, t_list **stack_b, int size_nodes)
{
	int	n;
	int	offset;

	n = 0;
	offset = vat_sqrt(size_nodes) + xoranard_sqrt(size_nodes);
	while (*stack_a)
	{
		if ((*stack_a)->index <= n)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			n++;
		}
		else if ((*stack_a)->index <= n + offset)
		{
			push_b(stack_a, stack_b);
			n++;
		}
		else
			rotate_a(stack_a);
	}
	push_elem_b_a(stack_a, stack_b, size_nodes);
}

void	push_elem_b_a(t_list **stack_a, t_list **stack_b, int size_nodes)
{
	int	i;

	i = size_nodes - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == i)
		{
			push_a(stack_b, stack_a);
			i--;
			size_nodes--;
		}
		else if (get_position(*stack_b, i) >= size_nodes / 2 + 1)
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}

int	vat_sqrt(int num)
{
	int	i;

	i = 0;
	while (i < num / 2)
	{
		if (i * i >= num)
			return (i);
		i++;
	}
	return (-1);
}

int	xoranard_sqrt(int num)
{
	int	i;

	i = 0;
	while (i <= num / 9)
	{
		if (i * i * i >= num)
			return (i);
		i++;
	}
	return (-1);
}
