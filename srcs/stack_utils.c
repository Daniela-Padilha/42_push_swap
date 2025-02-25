/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:25:27 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/08 14:25:27 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> gives the total number of nodes in the stack

int	stack_size(t_node *node)
{
	int	count;

	if (!node)
		return (0);
	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}

//info --> find the last node of the stack

t_node	*last_node(t_node *node)
{
	t_node	*last;

	if (!node)
		return (NULL);
	while (node->next)
		last = node->next;
	return (last);
}

//info --> find the node with the min value in a stack

t_node	*find_min(t_node *node)
{
	t_node	*min_node;
	long	min_value;

	if (!node)
		return (NULL);
	min_value = LONG_MAX;
	while (node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

//info --> find the node with the max value in a stack

t_node	*find_max(t_node *node)
{
	t_node	*max_node;
	long	max_value;

	if (!node)
		return (NULL);
	max_value = LONG_MIN;
	while (node)
	{
		if (node->value > max_value)
		{
			max_value = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

//info --> check if the stack is sorted in ascending order

bool	stack_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}
