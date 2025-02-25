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
	int	a_size;

	a_size = stack_size(*a);
	if (a_size-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (a_size-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (a_size > 3 && !stack_sorted(*a))
	{
		init_a_nodes(*a, *b);
		move_to_b(a, b);
		a_size--;
	}
	sort_three(a);
	while (*b)
	{
		init_b_nodes(*a, *b);
		move_to_a(a, b);
	}
	get_index(*a);
	final_sort(a);
}
