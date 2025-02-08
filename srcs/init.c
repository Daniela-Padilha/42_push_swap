/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:10:10 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/08 13:10:10 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack (t_stack *stack, int ac, char **av)
{
	char	**nbrs;
	int		i;
	int		j;

	if (ac == 1)
		return ;
	if (ac == 2)
		nbrs = ft_split(*av[1], ' ');
	else
	{

		i = 1;
		j = 0;
		while (av[i])
			nbrs[j++] = av[i++];
	}
}