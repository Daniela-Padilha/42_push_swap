/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:15:49 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/07 00:15:49 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> start the empty stacks
//			handle wrong number of args, or second arg empty (" ")
//			handle 2 or more args (./ 1 2 3 4 and ./ "1 2 3 4")
//			init stack a, put each nbr in a node, handle duplicates, signs...
//			check if stack a is sorted, and sort

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack_a(&a, ac, av);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		if (stack_size(a) == 3)
			sort_three(&a);
		else
			turk(&a, &b);
	}
	free_stack(&a);
	return (0);
}

void	print_stack(t_node *a)
{
	while (a)
	{
		ft_printf("%i ", a->value);
		a = a->next;
	}
	ft_printf("\n");
}
