/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:25:38 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/21 18:25:38 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> put the max value in the tail
//			and swap the first 2 nodes if necessary

void	sort_three(t_node **a)
{
	t_node	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		ra(a);
	else if (max_node == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

//info --> push 2 first nbrs to stack b
//			until stack a has 3 nbrs push to b while sorting
//			then sort 3, push all to stack
//			and put smallest nbr of a on top

void	turk(t_node **a, t_node **b)
{
	pb(a, b);
	pb(a, b);
	while (stack_size(a) > 3)
	{
		sort_b(b);
		pb(a, b);
	}
	sort_three(a);
	while (b)
		pa(b, a);
	final_sort(a);
}

//info -->

void	sort_b(t_node **b)
{
}

//info --> sorts the max and min nbrs in stack a

void	final_sort(t_node **a)
{
	t_node	*temp;

	temp = find_min(a);
	if (check_if_above_median(temp) == true)
	{
		while (temp != *a)
			ra(a);
	}
	else
	{
		while (temp != *a)
			rra(a);
	}
	temp = find_max(a);
	if (check_if_above_median(temp) == true)
	{
		while (temp)
			ra(a);
	}
	else
	{
		while (temp)
			rra(a);
	}
}
