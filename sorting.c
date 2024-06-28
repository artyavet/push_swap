/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:05:00 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:46:39 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_3_elements(t_list **s)
{
	if ((*s)->num > (*s)->next->num && (*s)->num < (*s)->next->next->num)
		swap_a(s);
	else if ((*s)->next->next->num < (*s)->next->num
		&& (*s)->next->next->num > (*s)->num)
	{
		reverse_rotate_a(s);
		swap_a(s);
	}
	else if ((*s)->num > (*s)->next->num && (*s)->num > (*s)->next->next->num)
	{
		rotate_a(s);
		if ((*s)->num > (*s)->next->num)
			swap_a(s);
	}
	else if ((*s)->num < (*s)->next->num
		&& (*s)->next->num > (*s)->next->next->num)
	{
		reverse_rotate_a(s);
		if ((*s)->num > (*s)->next->num)
			swap_a(s);
	}
}

void	sort_for_5_elem(t_list **stack_a, t_list **stack_b, int count_argc)
{
	int	i;

	i = 0;
	while (count_argc > 3)
	{
		if (get_position(*stack_a, i) == 0)
		{
			push_b(stack_a, stack_b);
			count_argc--;
			i++;
		}
		else if (get_position(*stack_a, i) >= count_argc / 2 + 1)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	sort_for_3_elements(stack_a);
	if ((*stack_b)->next)
	{
		push_a(stack_b, stack_a);
	}
	push_a(stack_b, stack_a);
}
