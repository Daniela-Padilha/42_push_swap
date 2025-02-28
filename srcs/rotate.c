/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:08:08 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/08 13:08:08 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> change the head to the tail
//		update the *prev and *next of the old head
//		update the *next of the old tail
//		update the *prev of the new head

static void	rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
}

//info --> brings the top node of a to the bottom

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

//info --> brings the top node of b to the bottom

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

//info --> does ra and rb at the same time

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
