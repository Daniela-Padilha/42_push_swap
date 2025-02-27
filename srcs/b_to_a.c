/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:24:30 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/22 17:24:30 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> find the node in stack a that will be the target
//			for the node in stack b (the closest bigger)

static void	find_target_b(t_node *a, t_node *b)
{
	t_node	*actual_a;
	t_node	*target_node;
	long	target_value;

	while (b)
	{
		target_value = LONG_MAX;
		actual_a = a;
		while (actual_a)
		{
			if (actual_a->value > b->value && actual_a->value < target_value)
			{
				target_value = actual_a->value;
				target_node = actual_a;
			}
			actual_a = actual_a->next;
		}
		if (target_value == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}


//info --> prepare to push the b node to the right place in stack a

void	init_b_nodes(t_node *a, t_node *b)
{
	get_index(a);
	get_index(b);
	find_target_b(a, b);
	analyze_cost(a, b);
	set_cheapest(b);
}
