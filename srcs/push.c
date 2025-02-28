/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:11:58 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/08 13:11:58 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> push a node from one stack to another
//			*next = NULL in case dest is empty
//			if not empty, update *next of new node and *prev of existing node

static void	ft_push(t_node **src, t_node **dest)
{
	t_node	*push_this;

	if (!*src)
		return ;
	push_this = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_this->prev = NULL;
	if (!*dest)
	{
		*dest = push_this;
		push_this->next = NULL;
	}
	else
	{
		(*dest)->prev = push_this;
		push_this->next = *dest;
		*dest = push_this;
	}
}

//info --> push the top node of b to the top of a

void	pa(t_node **b, t_node **a)
{
	ft_push(b, a);
	ft_printf("pa\n");
}

//info --> push the top node of a to the top of b

void	pb(t_node **a, t_node **b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
