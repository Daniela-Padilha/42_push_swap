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
void	init_stack_a(t_node **a, char **av);
void	add_node(t_node **stack, int nbr);
void	put_on_top(t_node **stack, t_node *top_node, char name);

//Nodes init
void	init_b_nodes(t_node *a, t_node *b);
void	init_a_nodes(t_node *a, t_node *b);
void	get_index(t_node *stack);
t_node	*find_cheapest(t_node *stack);

//Stack utils
int		stack_size(t_node *node);
t_node	*last_node(t_node *node);
t_node	*find_min(t_node *node);
t_node	*find_max(t_node *node);
bool	stack_sorted(t_node *node);

//Operations
void	pa(t_node **b, t_node **a);
void	pb(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//Algorithms
void	sort_three(t_node **a);
void	turk(t_node **a, t_node **b);

//Algorithms Utils
void	move_to_a(t_node **a, t_node **b);
void	move_to_b(t_node **a, t_node **b);
void	final_sort(t_node **a);

//Errors
int		syntax_error(char *str);
int		duplicate_error(t_node *stack, int value);
void	free_stack(t_node **node);
void	free_errors(t_node **stack);

#endif