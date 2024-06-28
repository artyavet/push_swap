/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:34:13 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:29:28 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if ((str[i] == '+' || str[i] == '-' ) && str[i + 1] == '\0')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	check_for_dublicates(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*cur;

	tmp = *stack_a;
	while (tmp->next)
	{
		cur = tmp->next;
		while (cur)
		{
			if (tmp->num == cur->num)
				exit_func(stack_a);
			cur = cur->next;
		}
		tmp = tmp->next;
	}
}

void	exit_func(t_list **stack_a)
{
	ft_lstclear(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	q_input_is_empty_or_only_spaces(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			exit(write(2, "Error\n", 6));
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32)
				j++;
			if (argv[i][j] == '\0')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			else
				break ;
		}
		i++;
	}
}
