/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:54:59 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/21 14:54:59 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//Stacks init

//Nodes init

//Stack utils
int		stack_size(t_node *node);
t_node	*last_node(t_node *node);
t_node	*find_min(t_node *node);
t_node	*find_max(t_node *node);
bool	stack_sorted(t_node *node);

//Operations
void	ft_push(t_node **src, t_node **dest);
void	pa(t_node **b, t_node **a);
void	pb(t_node **a, t_node **b);
void	swap(t_node **head);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//Algorithm
void	sort_three(t_node **a);
void	turk(t_node **a, t_node **b);

//Errors
void	free_stack(t_node *node);

#endif