/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:00:23 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:48:40 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid(int argc, char **argv, t_list **stack_a, int *count_nodes)
{
	long long	num;
	char		**arr;
	int			i;
	int			j;

	i = 1;
	while (i < argc)
	{
		arr = split(argv[i]);
		if (!arr)
			exit_func(stack_a);
		j = 0;
		while (arr[j])
		{
			(*count_nodes)++;
			if (check_current_line(arr[j]) == -1)
				exit_func(stack_a);
			num = ft_atoll(arr[j]);
			validation_helper(num, arr[j], stack_a);
			j++;
		}
		free_split_line(arr);
		i++;
	}
	check_for_dublicates(stack_a);
}

void	validation_helper(long long num, char *str, t_list **stack_a)
{
	t_list	*node;

	if (check_num_func(num, str) == -1)
		exit_func(stack_a);
	node = ft_lstnew(num);
	ft_lstadd_back(stack_a, node);
}

int	check_num_func(long long num, char *str)
{
	(void)str;
	if (num < INT_MIN || num > INT_MAX || ft_strlen(str) > 11)
		return (-1);
	return (1);
}

int	check_current_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' '
			|| (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (-1);
	}
	return (1);
}

void	free_split_line(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
