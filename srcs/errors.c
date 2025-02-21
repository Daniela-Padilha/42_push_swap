/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:23:33 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/07 14:23:33 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digit(char **nbrs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nbrs[j][i])
	{
		if (nbrs[j] > INT_MAX || nbrs[j] < INT_MIN)
			return (-1);
		while (nbrs[i])
		{
			if (ft_isdigit(i) == 1 || i == 43 || i == 45)
				i++;
			else
				return (-1);
		}
		j++;
	}
	return (0);
}

int	check_dup(char **nbrs)
{
	int	i;
	int	j;

	while (nbrs[j][i])
	{
	}
}

//info --> free the whole stack

void	free_stack(t_node *node)
{
	t_node	*tmp;

	if (!*node || !node)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
}
