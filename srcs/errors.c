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

#include "../push_swap.h"

void	check_args(int ac, char **av)
{
	char	**nbrs;
	int		i;
	int		j;

	if (ac == 1)
		return ;
	else if (ac == 2)
		nbrs = ft_split(*av[1], ' ');
	else
	{
		i = 1;
		j = 0;
		while (av[i])
			nbrs[j++] = av[i++];
	}
	if (check_digit(nbrs) == -1)
		return (ft_putstr_fd("Error\n", 2), free_arrays(nbrs));
	if (check_dup(nbrs) == -1)
		return (ft_putstr_fd("Error\n", 2), free_arrays(nbrs));
	free_arrays(nbrs);
	return ;
}


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