/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:09:55 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/08 13:09:55 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> change the tail to the head
//		update the *prev of the old head
//		update the *next and *prev of the new head
//		update the *next of the new tail

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

//info --> brings the bottom node of a to the top

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	ft_printf("stack a: ");
	print_stack(*a);
}

//info --> brings the bottom node of b to the top

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	ft_printf("stack b: ");
	print_stack(*b);
}

//info --> does rra and rrb at the same time

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	ft_printf("stack a: ");
	print_stack(*a);
	ft_printf("stack b: ");
	print_stack(*b);
}
