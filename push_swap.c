/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:45:44 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/28 21:15:41 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*cur;

	cur = *stack;
	while (cur)
	{
		tmp = *stack;
		while (tmp)
		{
			if (cur->num > tmp->num)
				cur->index += 1;
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

int	get_position(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	check(t_list **stack_a, t_list **stack_b, int count_nodes)
{
	if (count_nodes == 1)
		return ;
	if (is_sorted(*stack_a) == 1)
		return ;
	if (count_nodes == 2)
		swap_a(stack_a);
	else if (count_nodes == 3)
		sort_for_3_elements(stack_a);
	else if (count_nodes <= 5)
		sort_for_5_elem(stack_a, stack_b, count_nodes);
	else
		sort_butterfly(stack_a, stack_b, count_nodes);
}

int	is_sorted(t_list *stack)
{
	if (!(stack))
		return (1);
	while ((stack)->next)
	{
		if ((stack)->num > (stack)->next->num)
			return (-1);
		stack = (stack)->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_nodes;

	if (argc == 1)
		exit(1 && write(2, "Error\n", 6));
	count_nodes = 0;
	stack_a = NULL;
	stack_b = NULL;
	q_input_is_empty_or_only_spaces(argv);
	valid(argc, argv, &stack_a, &count_nodes);
	set_index(&stack_a);
	check(&stack_a, &stack_b, count_nodes);
	ft_lstclear(&stack_a);
	return (0);
}
