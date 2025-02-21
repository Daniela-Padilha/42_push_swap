/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:55:30 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/21 16:55:30 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> initialize stack a

void	init_stack (t_node **a, char **av)
{
	long	nbr;
	int		i;

	if (ac == 1)
		return ;
	if (ac == 2)
		nbr = ft_split(*av[1], ' ');
	else
	{

		i = 1;
		j = 0;
		while (av[i])
			nbrs[j++] = av[i++];
	}
}

//info -->

find_cheapest()
{
}

//info -->

find_target()
{
}

//info --> finds the median of the stack
//			returns true if the node is above
//			returns false if the node is below

bool	check_if_above_median(t_node **node)
{
}
