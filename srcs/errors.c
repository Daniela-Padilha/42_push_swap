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
	int	i;

	if (!(str[0] == '+' || str[0] == '-' || ft_isdigit((int)str[0])))
		return (1);
	if ((str[0] == '+' || str[0] == '-' ) || !ft_isdigit((int)str[1]))
		return (1);
	i = 2;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (1),
		i++;
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

void	free_errors(t_node **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
