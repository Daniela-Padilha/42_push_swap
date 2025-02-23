/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:24:38 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/22 17:24:38 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> find the node in stack b that will be the target
//			for the node in stack a (the closest smaller)

static void	find_target_a(t_node *a, t_node *b)
{
	t_node	*actual_b;
	t_node	*target_node;
	long	target_value;

	while (a)
	{
		target_value = LONG_MIN;
		actual_b = b;
		while (actual_b)
		{
			if (actual_b->value > a->value && actual_b->value < target_value)
			{
				target_value = actual_b->value;
				target_node = actual_b;
			}
			actual_b = actual_b->next;
		}
		if (target_value == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

//info --> sets the index of a node in the stack
//			checks if the node is above or below median

void	get_index(t_node *stack)
{
	int	i;
	int	median;

	i = 1;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

//info --> calculates the cost of pushing a to the target in b
//		push cost = nº of operations to bring a on top + nº of operations to
//					bring the target on top

static void	analyze_cost_a(t_node *a, t_node *b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	b_size = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = a_size - (a->index);
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += b_size - (a->target->index);
		a = a->next;
	}
}

//info --> check wich node is the cheapest based on the pushing cost

void	find_cheapest(t_node *stack)
{
	long	chapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

//info --> prepare to push the a node to the right place in stack b

void	init_a_nodes(t_node *a, t_node *b)
{
	get_index(a);
	get_index(b);
	find_target_a(a, b);
	analyze_cost_a(a, b);
	find_cheapest(a);
}