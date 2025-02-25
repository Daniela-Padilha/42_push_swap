/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:53:37 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/24 14:53:37 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> rr if it's the cheapest move, and update their index

static void	rotate_2(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	get_index(*a);
	get_index(*b);
}

//info --> rrr if it's the cheapest move, and update their index

static void	reverse_rotate_2(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	get_index(*a);
	get_index(*b);
}

//info --> prepares the b stack targets to receive the a nodes
//			until there are only 3 nodes in a

void	move_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_2(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_2(a, b, cheapest);
	put_on_top(a, cheapest, 'a');
	put_on_top(b, cheapest->target, 'b');
	pb(b, a);
}

//info --> prepares the a stack targets to receive the b nodes

void	move_to_a(t_node **a, t_node **b)
{
	put_on_top(a, (*b)->target, 'a');
	pa(b, a);
}

//info --> puts the min node on top of stack a

void	final_sort(t_node **a)
{
	t_node	*min_node;

	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->above_median == true)
			ra(a);
		else
			rra(a);
	}
}
