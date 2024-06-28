/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artyavet <artyavet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:09:59 by artyavet          #+#    #+#             */
/*   Updated: 2024/06/26 22:17:19 by artyavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	result;
	int			poc;

	poc = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			poc = -1;
	}
	if (nptr[i] == '+' || nptr[i] == '-' || nptr[i] == '\0')
		return (LONG_MAX);
	while (nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i++] - 48) + (result * 10);
	}
	if (!nptr[i])
		return (result * poc);
	return (LONG_MAX);
}
