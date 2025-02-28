/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:05:24 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/08 13:05:24 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> change the *head to the 2º node
//		update the *prev and *next of the old head
//		if there is a 3º node, update its' *prev
//		update the *prev and *next of the new head

static void	swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

//info --> swaps the first two nodes in a

void	sa(t_node **a)
{
	swap(a);
	get_index(*a);
	ft_printf("sa\n");
}

//info --> swaps the first two nodes in b

void	sb(t_node **b)
{
	swap(b);
	get_index(*b);
	ft_printf("sb\n");
}

//info --> swaps the first two nodes in a and b at the same time

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	get_index(*a);
	get_index(*b);
	ft_printf("ss\n");
}
