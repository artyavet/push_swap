/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:55:07 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:56:14 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_b);
	*stack_b = tmp;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
