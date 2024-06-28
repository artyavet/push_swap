/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_for_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:49:49 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:30:26 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	swap_a(t_list **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
