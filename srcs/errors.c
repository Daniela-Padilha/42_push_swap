/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:23:33 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/07 14:23:33 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//info --> check for syntax errors in the string and return 1 if found

int	syntax_error(char *str)
{
	if (*str == '+' || *str == '-' )
		str++;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

//info --> check for duplicates in the string and return 1 if found

int	duplicate_error(t_node *stack, int value)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

//info --> free the whole stack

void	free_stack(t_node **node)
{
	t_node	*tmp;
	t_node	*actual;

	if (!node)
		return ;
	actual = *node;
	while (actual)
	{
		tmp = actual->next;
		free(actual);
		actual = tmp;
	}
	*node = NULL;
}

//info --> if an error is found free stack and print error message

void	free_errors(t_node **stack, int ac, char **av)
{
	if (ac > 2)
	{
		free_stack(stack);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	free_arrays((void **)av);
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
