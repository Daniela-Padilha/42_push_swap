/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:55:30 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/21 16:55:30 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> initialize stack a by checking for letters, overflow and duplicates
//			if no errors are found add the new node to the stack

void	init_stack_a(t_node **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
		{
			ft_printf("syntax\n");
			free_errors(a);
		}
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_printf("overflow\n");
			free_errors(a);
		}
		if (duplicate_error(*a, (int)nbr))
		{
			ft_printf("dup\n");
			free_errors(a);
		}
		add_node(a, (int)nbr);
		(*a)->index = 0;
		(*a)->push_cost = 0;
		(*a)->above_median = 0;
		(*a)->cheapest = 0;
		i++;
	}
}

//info --> search for the last node in the stack and add the new one after

void	add_node(t_node **stack, int nbr)
{
	t_node	*new_node;
	t_node	*last;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = nbr;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

//info --> search the stack for the cheapest node and return it

t_node	*find_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//info --> moves a node from stack name to the top of the stack

void	put_on_top(t_node **stack, t_node *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_median == true)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
